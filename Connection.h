#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

struct Connection {
    int descriptor;
};

struct Connection * Connection_construct();

void Connection_destruct(struct Connection * connection);

void Connection_close(struct Connection * connection);

#endif
