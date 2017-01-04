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
    strcat(response->buffer, "\n");


	return response;
}

void Response_destruct(struct Response * response)
{
    free(response);
}

void Response_addNumber(struct Response * response, long int number)
{
    response->buffer[strlen(response->buffer)] = '\0'; // remove new line
    char addition[sizeof(long int) + 1];
    sprintf(addition, "%ld", number);
    strcat(response->buffer, addition);
    strcat(response->buffer, "\n");
}
