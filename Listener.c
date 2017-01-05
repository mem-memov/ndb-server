#include "Listener.h"
#include "Connection.h"
#include "Request.h"
#include "Response.h"
#include "Error.h"
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

struct Listener * Listener_construct(int port, int connectionLimit)
{
	struct Listener * listener = malloc(sizeof(struct Listener));

	listener->port = port;
	listener->connectionLimit = connectionLimit;
	listener->descriptor = -2;

	return listener;
}

void Listener_destruct(struct Listener * listener)
{
    free(listener);
}

void Listener_open(struct Listener * listener)
{
    Error_inListenerBeforeOpeningSocket(listener->descriptor);

    listener->descriptor = socket(PF_INET, SOCK_STREAM, 0);

    Error_inListenerAfterOpeningSocket(listener->descriptor);
}

void Listener_bind(struct Listener * listener)
{
    Error_inListenerBeforeBindingToPort(listener->descriptor);

    int reuse = 1;

    int setSocketOptionResult = setsockopt(listener->descriptor, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int));

    Error_inListenerAfterSettingSocketOption(setSocketOptionResult);

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(listener->port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int bindResult = bind(listener->descriptor, (struct sockaddr *)&name, sizeof(name));

    Error_inListenerAfterBindingToPort(bindResult);
}

void Listener_listen(struct Listener * listener)
{
    Error_inListenerBeforeListening(listener->descriptor);

    int listenResult = listen(listener->descriptor, listener->connectionLimit);

    Error_inListenerAfterListening(listenResult);
}

struct Connection * Listener_accept(struct Listener * listener, int bufferLength)
{
    Error_inListenerBeforeAcceptingConnection(listener->descriptor);

    struct sockaddr_storage clientAddress;
    unsigned int clientAddressSize = sizeof(clientAddress);
    int connectionDescriptor = accept(listener->descriptor, (struct sockaddr *)&clientAddress, &clientAddressSize);

    Error_inListenerAfterAcceptingConnection(connectionDescriptor);

    struct Request * request = Request_construct(bufferLength);
    struct Response * response = Response_construct(bufferLength);
    struct Connection * connection = Connection_construct(connectionDescriptor, request, response);

    return connection;
}

void Listener_close(struct Listener * listener)
{
    close(listener->descriptor);
    listener->descriptor = -2;
}
