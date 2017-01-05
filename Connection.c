#include "Connection.h"
#include "Request.h"
#include "Response.h"
#include "Error.h"
#include <stdlib.h>
#include <unistd.h>

struct Connection * Connection_construct(int descriptor, struct Request * request, struct Response * response)
{
	struct Connection * connection = malloc(sizeof(struct Connection));

	connection->descriptor = descriptor;
	connection->request = request;
	connection->response = response;

	return connection;
}

void Connection_destruct(struct Connection * connection)
{
    Request_destruct(connection->request);
    Response_destruct(connection->response);
    free(connection);
}

struct Request * Connection_request(struct Connection * connection)
{
    return connection->request;
}

struct Response * Connection_response(struct Connection * connection)
{
    return connection->response;
}

void Connection_close(struct Connection * connection)
{
    close(connection->descriptor);
}

void Connection_receive(struct Connection * connection)
{
    Request_clean(connection->request);
    Response_clean(connection->response);

    int receivedLength;
    int availableLength = Request_maxLength(connection->request) - 1; // string end

    do {
        receivedLength = recv(connection->descriptor, Request_body(connection->request), availableLength, 0);
        availableLength -= receivedLength;
        Error_inConnectionWhileReceiving(availableLength);
    } while (receivedLength > 0 && 0 == Request_isFinished(connection->request));
}

void Connection_send(struct Connection * connection)
{
    int sendResult = send(connection->descriptor, Response_body(connection->response), Response_length(connection->response), 0);
    Error_inConnectionAfterSending(sendResult);

    Request_clean(connection->request);
    Response_clean(connection->response);
}

char Connection_mustClose(struct Connection * connection)
{
    if (1 == Request_isCommand(connection->request, "exit")) {
        return 1;
    } else {
        return 0;
    }
}
