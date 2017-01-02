#include "Error.h"
#include <stdlib.h>
#include <string.h>

struct Error * Error_construct(char * message, int code)
{
	struct Error * error = malloc(sizeof(struct Error));

	return error;
}

void Error_destruct(struct Error * error)
{
    free(error->message);
    free(error);
}

void Error_beforeListenerOpeningSocket(int listenerDescriptor)
{
    if (0 <= listenerDescriptor) {
        frintf(stderr, "Error before listener opening socket.\n");
        exit(1);
    }
}

void Error_afterListenerOpeningSocket(int listenerDescriptor)
{
    if (-1 == listenerDescriptor) {
        frintf(stderr, "Error after listener opening socket.\n");
        exit(1);
    }
}

void Error_beforeListenerBindingToPort(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        frintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_afterListenerSettingSocketOption(int setSocketOptionResult)
{
    if (-1 == setSocketOptionResult) {
        frintf(stderr, "Error after listener setting socket option.\n");
        exit(1);
    }
}

void Error_afterListenerBindingToPort(int bindResult)
{
    if (-1 == bindResult) {
        frintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_beforeListenerListening(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        frintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_afterListenerListening(int listenResult)
{
    if (-1 == listenResult) {
        frintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_beforeListenerAcceptingConnection(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        frintf(stderr, "Error before listener accepting connection.\n");
        exit(1);
    }
}

void Error_afterListenerAcceptingConnection(int connectionDescriptor)
{
    if (-1 == connectionDescriptor) {
        frintf(stderr, "Error after listener accepting connection.\n");
        exit(1);
    }
}
