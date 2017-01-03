#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "Listener.h"
#include "Application.h"

struct Server {
    int port;
    int connectionLimit;
    int bufferLength;
    struct Listener * listener;
    struct Application * application;
};

struct Server * Server_construct(int port, int connectionLimit, int bufferLength, struct Application * application);

void Server_destruct(struct Server * server);

void Server_start(struct Server * server);

void Server_stop(struct Server * server);

#endif
