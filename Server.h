#ifndef SERVER_HEADER
#define SERVER_HEADER

struct Server {
    int port;
    int connectionLimit;
    struct Listener * listener;
};

struct Server * Server_construct(int port, int connectionLimit);

void Server_destruct(struct Server * server);

void Server_start(struct Server * server);

void Server_stop(struct Server * server);

#endif
