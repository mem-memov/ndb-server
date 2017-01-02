#include "Server.h"
#include "Signal.h"

struct Server * server;

int main(int argc, char *argv[])
{
    struct Signal * sigint = Signal_construct(SIGINT, Server_handleShutDown);
    Signal_catch(sigint);

    int port = 43152;
    int connectionLimit = 10;

    server = Server_construct(port, connectionLimit);

    Server_start(server);

    return(0);
}
