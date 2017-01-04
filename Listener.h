#ifndef LISTENER_HEADER
#define LISTENER_HEADER

#include "Connection.h"

struct Listener {
    int port;
    int connectionLimit;
    int descriptor;
};

struct Listener * Listener_construct(int port, int connectionLimit);

void Listener_destruct(struct Listener * listener);

void Listener_open(struct Listener * listener);

void Listener_bind(struct Listener * listener);

void Listener_listen(struct Listener * listener);

struct Connection * Listener_accept(struct Listener * listener, int bufferLength);

void Listener_close(struct Listener * listener);

#endif
