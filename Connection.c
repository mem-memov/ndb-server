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
    int filledLength;
    char lastCharacter;

    do {
        receivedLength = recv(connection->descriptor, buffer, availableLength, 0);
        availableLength -= receivedLength;
        Error_whileConnectionReceiving(availableLength);
        filledLength = bufferLength - availableLength - 1;
        lastCharacter = buffer[filledLength - 1];
    } while (receivedLength > 0 && lastCharacter != '\n');

    buffer[filledLength] = '\0';
    filledLength++;

    return filledLength;
}

void Connection_send(struct Connection * connection, char * buffer, int bufferLength)
{
    int sendResult = send(connection->descriptor, buffer, bufferLength, 0);
    Error_afterConnectionSending(sendResult);
}
