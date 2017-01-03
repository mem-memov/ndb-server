#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
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
        fprintf(stderr, "Error before listener opening socket.\n");
        exit(1);
    }
}

void Error_afterListenerOpeningSocket(int listenerDescriptor)
{
    if (-1 == listenerDescriptor) {
        fprintf(stderr, "Error after listener opening socket.\n");
        exit(1);
    }
}

void Error_beforeListenerBindingToPort(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_afterListenerSettingSocketOption(int setSocketOptionResult)
{
    if (-1 == setSocketOptionResult) {
        fprintf(stderr, "Error after listener setting socket option.\n");
        exit(1);
    }
}

void Error_afterListenerBindingToPort(int bindResult)
{
    if (-1 == bindResult) {
        fprintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_beforeListenerListening(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_afterListenerListening(int listenResult)
{
    if (-1 == listenResult) {
        fprintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_beforeListenerAcceptingConnection(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener accepting connection.\n");
        exit(1);
    }
}

void Error_afterListenerAcceptingConnection(int connectionDescriptor)
{
    if (-1 == connectionDescriptor) {
        fprintf(stderr, "Error after listener accepting connection.\n");
        exit(1);
    }
}

void Error_whileConnectionReceiving(int availableBufferLength)
{
    if (0 > availableBufferLength) {
        fprintf(stderr, "Error while reading connection. Available buffer length: %d.\n", availableBufferLength);
        exit(1);
    }
}

void Error_afterConnectionSending(int sendResult)
{
    if (-1 == sendResult) {
        fprintf(stderr, "Error while sending to connection.\n");
        exit(1);
    }
}

void Error_afterServerForking(int processId)
{
    if (-1 == processId) {
        fprintf(stderr, "Error after server creating a fork.\n");
        exit(1);
    }
}

void Error_afterApplicationCreatingPipe(int pipeResult)
{
    if (-1 == pipeResult) {
        fprintf(stderr, "Error after application creates a pipe.\n");
        exit(1);
    }
}

void Error_afterApplicationForking(int processId)
{
    if (-1 == processId) {
        fprintf(stderr, "Error after application creating a fork.\n");
        exit(1);
    }
}

void Error_afterApplicationExecuting()
{
    fprintf(stderr, "Error after application executing.\n");
    exit(1);
}

void Error_whileApplicationResponding(int responseLength, int maxResponseLength)
{
    if (responseLength > maxResponseLength) {
        fprintf(stderr, "Error while application responding. Response length violated.\n");
        exit(1);
    }
}
