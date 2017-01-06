#include "Response.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Response * Response_construct(int maxLength)
{
	struct Response * response = malloc(sizeof(struct Response));

	Error_inResponseWhileConstructingWithMaxLength(maxLength);
	response->maxLength = maxLength;

    response->body = malloc(response->maxLength);
    Response_clean(response);

	return response;
}

void Response_destruct(struct Response * response)
{
    free(response->body);
    free(response);
}

char * Response_body(struct Response * response)
{
    return response->body;
}

int Response_length(struct Response * response)
{
    Error_inResponseBeforeLength(response->body[response->maxLength]);

    return strlen(response->body);
}

void Response_clean(struct Response * response)
{
    memset(response->body, '\0', response->maxLength);
    response->body[0] = '\n';
}

void Response_addNumber(struct Response * response, long int number)
{
    Error_inResponseBeforeAddingNumber(response->body[response->maxLength]);

    // remove new line
    char *pos;
    if ((pos=strchr(response->body, '\n')) != NULL)
    {
        *pos = '\0';
    }

    char addition[sizeof(long int) + 1];
    sprintf(addition, "%ld", number);

    if (0 < strlen(response->body))
    {
        strcat(response->body, " ");
    }

    strcat(response->body, addition);

    // append new line
    response->body[strlen(response->body)] = '\n';
}

void Response_addNumbers(struct Response * response, long int * buffer, long int bufferLength, long int total)
{
    int i = 0;
    while (i < bufferLength && i < total)
    {
        Response_addNumber(response, buffer[i]);
        i++;
    }
}
