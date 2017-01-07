#include "Request.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

struct Request * Request_construct(int maxLength)
{
	struct Request * request = malloc(sizeof(struct Request));

    Error_inRequestWhileConstructingWithMaxLength(maxLength);
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
    Error_inRequestBeforeFinishedCheck(request->body[request->maxLength]);

    char lastCharacter = request->body[strlen(request->body) - 1];

    if ('\n' == lastCharacter)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char Request_isCommand(struct Request * request, char * command)
{
    Error_inRequestBeforeCommandCheck(request->body[request->maxLength]);

    if (strstr(request->body, command) == request->body)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long int Request_getArgument(struct Request * request, int orderNumber)
{
    Error_inRequestBeforeGettingArgument(request->body[request->maxLength]);

    int wordCount = 0;
    char character;
    int requestLength = strlen(request->body) + 1;
    int argumentLength = sizeof(long int) + 1;
    char argument[argumentLength];
    char isFound = 0;
    char argumentIndex = 0;
    int i;

    for (i = 0; i < requestLength; i++)
    {
        character = request->body[i];

        if (' ' == character)
        {
            if (wordCount == orderNumber)
            {
                break;
            }

            wordCount++;
            argumentIndex = 0;
            memset(argument, '\0', argumentLength);
        }
        else
        {
            if (wordCount == orderNumber)
            {
                isFound = 1;
                argument[argumentIndex] = character;
                argument[argumentIndex + 1] = '\0';
                argumentIndex++;

                if ((argumentLength - 2) == argumentIndex)
                {
                    break;
                }
            }
        }
    }

    Error_inRequestAfterGettingArgument(isFound, orderNumber);

    return strtol(argument, NULL, 10);
}

long int Request_countArguments(struct Request * request)
{
    Error_inRequestBeforeGettingArgument(request->body[request->maxLength]);

    int count = 0;
    char character;
    int requestLength = strlen(request->body) + 1;
    int i;
    for (i = 0; i < requestLength; i++)
    {
        character = request->body[i];

        if (' ' == character)
        {
            count++;
        }
    }

    return count;
}

void Request_getArguments(struct Request * request, long int * arguments, long int length)
{
    Error_inRequestBeforeGettingArguments(request->body[request->maxLength]);

    long int n;
    for (n = 0; n < length; n++)
    {
        arguments[n] = Request_getArgument(request, n+1);
    }
}

char Request_isEmpty(struct Request * request)
{
    if ('\0' == request->body[0])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
