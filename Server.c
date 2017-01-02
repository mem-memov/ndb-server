#include "Server.h"
#include "Listener.h"
#include "Connection.h"
#include <stdlib.h>
#include <unistd.h>

struct Server * Server_construct(int port, int connectionLimit)
{
	struct Server * server = malloc(sizeof(struct Server));

	server->port = port;
	server->connectionLimit = connectionLimit;
	server->listener = NULL;

	return server;
}

void Server_destruct(struct Server * server)
{
    if (NULL != server->listener) {
        Listener_destruct(server->listener);
    }

    free(server);
}

void Server_start(struct Server * server)
{
    server->listener = Listener_construct(server->port, server->connectionLimit);

    Listener_open(server->listener);
    Listener_bind(server->listener);
    Listener_listen(server->listener);

    while (1) {
        struct Connection * connection = Listener_accept(server->listener);
        pid_t processId = fork();
        if (0 == processId) { // child process code
            Listener_close(server->listener);

            Connection_close(connection);
            exit(0);
        }
        Connection_close(connection);
    }
}

void Server_stop(struct Server * server)
{

}


