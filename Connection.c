#include "Connection.h"
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

int Connection_receive(struct Connection * connection, char * buffer, int bufferLength)
{
    int receivedLength;
    int availableLength = bufferLength - 1;

    do {
        receivedLength = recv(connection->descriptor, buffer, availableLength, 0);
        availableLength -= receivedLength;
        Error_whileConnectionReceiving(availableLength);
    } while (receivedLength > 0 && availableLength > 0);

    int filledLength = bufferLength - availableLength - 1;

    buffer[filledLength] = '\0';
    filledLength++;

    return filledLength;
}

void Connection_send(struct Connection * connection, char * buffer, int bufferLength)
{
    int sendResult = send(connection->descriptor, buffer, bufferLength, 0);
    Error_afterConnectionSending(sendResult);
}
