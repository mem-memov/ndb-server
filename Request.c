#include "Request.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

struct Request * Request_construct(int maxLength)
{
	struct Request * request = malloc(sizeof(struct Request));

    Error_whileRequestConstructingWithMaxLength(maxLength);
    request->maxLength = maxLength;

    request->body = malloc(request->maxLength);
    Request_clean(request);

	return request;
}

void Request_destruct(struct Request * request)
{
    free(request->body);
    free(request);
}

char * Request_body(struct Request * request)
{
    return request->body;
}

int Request_maxLength(struct Request * request)
{
    return request->maxLength;
}

void Request_clean(struct Request * request)
{
    memset(request->body, '\0', request->maxLength);
}

char Request_isFinished(struct Request * request)
{
    Error_beforeRequestFinishedCheck(request->body[request->maxLength]);

    char lastCharacter = request->body[strlen(request->body) - 1];

    if ('\n' == lastCharacter) {
        return 1;
    } else {
        return 0;
    }
}

char Request_isCommand(struct Request * request, char * command)
{
    Error_beforeRequestCommandCheck(request->body[request->maxLength]);

    if (strstr(request->body, command) == request->body) {
        return 1;
    } else {
        return 0;
    }
}

long int Request_getArgument(struct Request * request, int orderNumber)
{
    Error_beforeRequestGettingArgument(request->body[request->maxLength]);

    int wordCount = 0;
    char character;
    int requestLength = strlen(request->body) + 1;
    int argumentLength = sizeof(long int) + 1;
    char argument[argumentLength];
    char isFound = 0;
    char argumentIndex = 0;
    int i;

    for (i = 0; i < requestLength; i++) {
        character = request->body[i];
        if (' ' == character) {
            if (wordCount == orderNumber) {
                break;
            }
            wordCount++;
            argumentIndex = 0;
            memset(argument, '\0', argumentLength);
        } else {
            if (wordCount == orderNumber) {
                isFound = 1;
                argument[argumentIndex] = character;
                argument[argumentIndex + 1] = '\0';
                argumentIndex++;
                if ((argumentLength - 2) == argumentIndex) {
                    break;
                }
            }
        }
    }

    Error_afterRequestGettingArgument(isFound, orderNumber);

    return strtol(argument, NULL, 10);
}


