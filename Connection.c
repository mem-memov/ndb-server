#include "Connection.h"
#include "Request.h"
#include "Response.h"
#include "Error.h"
#include <stdlib.h>
#include <unistd.h>

struct Connection * Connection_construct(int descriptor)
{
	struct Connection * connection = malloc(sizeof(struct Connection));

	connection->descriptor = descriptor;

	return connection;
}

void Connection_destruct(struct Connection * connection)
{
    free(connection);
}

void Connection_close(struct Connection * connection)
{
    close(connection->descriptor);
}

void Connection_receive(struct Connection * connection, struct Request * request)
{
    int receivedLength;
    int availableLength = Request_maxLength(request);

    do {
        receivedLength = recv(connection->descriptor, Request_body(request), availableLength, 0);
        availableLength -= receivedLength;
        Error_whileConnectionReceiving(availableLength);
    } while (receivedLength > 0 && 0 == Request_isFinished(request));
}

void Connection_send(struct Connection * connection, struct Response * response)
{
    int sendResult = send(connection->descriptor, Response_body(response), Response_length(response), 0);
    Error_afterConnectionSending(sendResult);
}
