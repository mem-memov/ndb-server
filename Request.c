#include "Request.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

struct Request * Request_construct(char * body, int length)
{
	struct Request * request = malloc(sizeof(struct Request));

    if (body[length] != '\0') {
        // error: wrong format
    }

    request->body = malloc(length);
    strcpy(request->body, body);

	return request;
}

void Request_destruct(struct Request * request)
{
    free(request->body);
    free(request);
}

char Request_isCommand(struct Request * request, char * command)
{
    if (strstr(request->body, command) == request->body) {
        return 1;
    } else {
        return 0;
    }
}

long int Request_getArgument(struct Request * request, int orderNumber)
{
    int wordCount = 0;
    char character;
    int requestLength = strlen(request->body) + 1;
    int argumentLength = sizeof(long int) + 1;
    char argument[argumentLength];
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
                argument[argumentIndex] = character;
                argument[argumentIndex + 1] = '\0';
                argumentIndex++;
                if ((argumentLength - 2) == argumentIndex) {
                    break;
                }
            }
        }
    }

    return strtol(argument, NULL, 10);
}


