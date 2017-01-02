#include "Server.h"
#include "Signal.h"
#include <stdlib.h>

struct Server * server = NULL;

void handleShutDown()
{
    if (NULL != server) {
        Server_stop(server);
    }

    exit(0);
}

int main(int argc, char *argv[])
{
    struct Signal * sigint = Signal_constructSigint(handleShutDown);
    Signal_catch(sigint);

    int port = 43152;
    int connectionLimit = 10;

    server = Server_construct(port, connectionLimit);

    Server_start(server);

    return(0);
}
