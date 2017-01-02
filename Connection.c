#include "Connection.h"
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
