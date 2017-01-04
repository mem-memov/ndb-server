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
        Error_afterServerForking((int)processId);

        if (0 == processId) { // child process code
            Listener_close(server->listener);

            struct Request * request = Request_construct(server->bufferLength);
            Connection_receive(connection, request);

            struct Response * response = Response_construct(server->bufferLength);
            Application_execute(server->application, request,response);
            Connection_send(connection, response);

            Connection_close(connection);
            exit(0);
        }
        Connection_close(connection);
    }
}

void Server_stop(struct Server * server)
{
    if (NULL != server->listener) {
        Listener_close(server->listener);
    }
}




