#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Error_inApplicationWhileExecutingWithSmallBuffer(int bufferLength, long int total)
{
    if (bufferLength < total) {
        fprintf(stderr, "Error while application executing. Buffer size %d is less than %ld.\n", bufferLength, total);
        exit(1);
    }
}

void Error_inApplicationWhileExecutingWithUnknownCommand()
{
    fprintf(stderr, "Error while application executing. Command not known.\n");
    exit(1);
}

void Error_inConnectionWhileReceiving(int availableBufferLength)
{
    if (0 > availableBufferLength) {
        fprintf(stderr, "Error while reading connection. Available buffer length: %d.\n", availableBufferLength);
        exit(1);
    }
}

void Error_inConnectionAfterSending(int sendResult)
{
    if (-1 == sendResult) {
        fprintf(stderr, "Error while sending to connection.\n");
        exit(1);
    }
}

void Error_inListenerBeforeOpeningSocket(int listenerDescriptor)
{
    if (0 <= listenerDescriptor) {
        fprintf(stderr, "Error before listener opening socket.\n");
        exit(1);
    }
}

void Error_inListenerAfterOpeningSocket(int listenerDescriptor)
{
    if (-1 == listenerDescriptor) {
        fprintf(stderr, "Error after listener opening socket.\n");
        exit(1);
    }
}

void Error_inListenerBeforeBindingToPort(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_inListenerAfterSettingSocketOption(int setSocketOptionResult)
{
    if (-1 == setSocketOptionResult) {
        fprintf(stderr, "Error after listener setting socket option.\n");
        exit(1);
    }
}

void Error_inListenerAfterBindingToPort(int bindResult)
{
    if (-1 == bindResult) {
        fprintf(stderr, "Error before listener binding to port.\n");
        exit(1);
    }
}

void Error_inListenerBeforeListening(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_inListenerAfterListening(int listenResult)
{
    if (-1 == listenResult) {
        fprintf(stderr, "Error before listener listening.\n");
        exit(1);
    }
}

void Error_inListenerBeforeAcceptingConnection(int listenerDescriptor)
{
    if (0 > listenerDescriptor) {
        fprintf(stderr, "Error before listener accepting connection.\n");
        exit(1);
    }
}

void Error_inListenerAfterAcceptingConnection(int connectionDescriptor)
{
    if (-1 == connectionDescriptor) {
        fprintf(stderr, "Error after listener accepting connection.\n");
        exit(1);
    }
}

void Error_inRequestWhileConstructingWithMaxLength(int maxLength)
{
    if (maxLength < 2) {
        fprintf(stderr, "Error while constructing request. Maximum request length %d is too small.\n", maxLength);
        exit(1);
    }
}

void Error_inRequestBeforeFinishedCheck(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error while checking request is finished. Request body overflow.\n");
        exit(1);
    }
}

void Error_inRequestBeforeCommandCheck(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error while testing request for command. Request body overflow.\n");
        exit(1);
    }
}

void Error_inRequestBeforeGettingArgument(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before geting request argument. Request body overflow.\n");
        exit(1);
    }
}

void Error_inRequestAfterGettingArgument(char isFound, int orderNumber)
{
    if (0 == isFound) {
        fprintf(stderr, "Error after geting request argument. Argument %d not found.\n", orderNumber);
        exit(1);
    }
}

void Error_inResponseWhileConstructingWithMaxLength(int maxLength)
{
    if (maxLength < 2) {
        fprintf(stderr, "Error while constructing response. Maximum response length %d is too small.\n", maxLength);
        exit(1);
    }
}

void Error_inResponseBeforeLength(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before geting response length. Resopnse body overflow.\n");
        exit(1);
    }
}

void Error_inResponseBeforeAddingNumber(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before response adding number. Resopnse body overflow.\n");
        exit(1);
    }
}

void Error_inServerAfterForking(int processId)
{
    if (-1 == processId) {
        fprintf(stderr, "Error after server creating a fork.\n");
        exit(1);
    }
}
