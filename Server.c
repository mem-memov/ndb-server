#include "Server.h"
#include "Listener.h"
#include "Connection.h"
#include "Request.h"
#include "Response.h"
#include "Application.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

struct Server * Server_construct(int port, int connectionLimit, int bufferLength, struct Application * application)
{
	struct Server * server = malloc(sizeof(struct Server));

	server->port = port;
	server->connectionLimit = connectionLimit;
	server->bufferLength = bufferLength;
	server->listener = NULL;
    server->application = application;

	return server;
}

void Server_destruct(struct Server * server)
{
    if (NULL != server->listener)
    {
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

    while (1)
    {
        struct Connection * connection = Listener_accept(server->listener, server->bufferLength);

        pid_t processId = fork();
        Error_inServerAfterForking((int)processId);

        if (0 == processId)
        { // child process code
            Listener_close(server->listener);

            while (1) {
                Connection_receive(connection);

                if (1 == Connection_isIdle(connection))
                {
                    continue;
                }

                if (1 == Connection_mustClose(connection))
                {
                    Connection_close(connection);
                    exit(0);
                }

                Application_execute(server->application, Connection_request(connection), Connection_response(connection));
                Connection_send(connection);
            }
        }

        Connection_close(connection);
    }
}

void Server_stop(struct Server * server)
{
    if (NULL != server->listener)
    {
        Listener_close(server->listener);
    }
}




