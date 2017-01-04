#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void Error_whileApplicationExecutingWithSmallBuffer(int bufferLength, long int total)
{
    if (bufferLength < total) {
        fprintf(stderr, "Error while application executing. Buffer size %d is less than %ld.\n", bufferLength, total);
        exit(1);
    }
}

void Error_whileRequestConstructingWithMaxLength(int maxLength)
{
    if (maxLength < 2) {
        fprintf(stderr, "Error while constructing request. Maximum request length %d is too small.\n", maxLength);
        exit(1);
    }
}

void Error_beforeRequestFinishedCheck(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error while checking request is finished. Request body overflow.\n");
        exit(1);
    }
}

void Error_beforeRequestCommandCheck(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error while testing request for command. Request body overflow.\n");
        exit(1);
    }
}

void Error_beforeRequestGettingArgument(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before geting request argument. Request body overflow.\n");
        exit(1);
    }
}

void Error_afterRequestGettingArgument(char isFound, int orderNumber)
{
    if (0 == isFound) {
        fprintf(stderr, "Error after geting request argument. Argument %d not found.\n", orderNumber);
        exit(1);
    }
}

void Error_whileResponseConstructingWithMaxLength(int maxLength)
{
    if (maxLength < 2) {
        fprintf(stderr, "Error while constructing response. Maximum response length %d is too small.\n", maxLength);
        exit(1);
    }
}

void Error_beforeResponseLength(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before geting response length. Resopnse body overflow.\n");
        exit(1);
    }
}

void Error_beforeResponseAddingNumber(char endCharacter)
{
    if ('\0' != endCharacter) {
        fprintf(stderr, "Error before response adding number. Resopnse body overflow.\n");
        exit(1);
    }
}
