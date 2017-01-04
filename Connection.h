#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include "Request.h"
#include "Response.h"

struct Connection {
    int descriptor;
    struct Request * request;
    struct Response * response;
};

struct Connection * Connection_construct(int descriptor, struct Request * request, struct Response * response);

void Connection_destruct(struct Connection * connection);

struct Request * Connection_request(struct Connection * connection);

struct Response * Connection_response(struct Connection * connection);

void Connection_close(struct Connection * connection);

void Connection_receive(struct Connection * connection);

void Connection_send(struct Connection * connection);

char Connection_mustClose(struct Connection * connection);

#endif
