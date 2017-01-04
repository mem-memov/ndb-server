#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include "Request.h"
#include "Response.h"

struct Connection {
    int descriptor;
};

struct Connection * Connection_construct();

void Connection_destruct(struct Connection * connection);

void Connection_close(struct Connection * connection);

void Connection_receive(struct Connection * connection, struct Request * request);

void Connection_send(struct Connection * connection, struct Response * response);

#endif
