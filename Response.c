#include "Response.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Response * Response_construct(char * buffer, int maxResponseLength)
{
	struct Response * response = malloc(sizeof(struct Response));

	response->maxResponseLength = maxResponseLength;

    response->buffer = buffer;
    memset(response->buffer, '\0', response->maxResponseLength);
    response->buffer[0] = '\n';


	return response;
}

void Response_destruct(struct Response * response)
{
    free(response);
}

void Response_addNumber(struct Response * response, long int number)
{
    // remove new line
    char *pos;
    if ((pos=strchr(response->buffer, '\n')) != NULL) {
        *pos = '\0';
    }

    char addition[sizeof(long int) + 1];
    sprintf(addition, "%ld", number);
    if (0 < strlen(response->buffer)) {
        strcat(response->buffer, " ");
    }
    strcat(response->buffer, addition);

    // append new line
    response->buffer[strlen(response->buffer)] = '\n';
}

int Response_length(struct Response * response)
{
    return strlen(response->buffer);
}
