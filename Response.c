#include "Response.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Response * Response_construct(int maxLength)
{
	struct Response * response = malloc(sizeof(struct Response));

    if (maxLength < 1) {
        // error: wrong format
    }
	response->maxLength = maxLength;

    int realLength = response->maxLength + 1; // keep string end
    response->body = malloc(realLength);
    memset(response->body, '\0', realLength);

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
    return strlen(response->body);
}

void Response_addNumber(struct Response * response, long int number)
{
    // remove new line
    char *pos;
    if ((pos=strchr(response->body, '\n')) != NULL) {
        *pos = '\0';
    }

    char addition[sizeof(long int) + 1];
    sprintf(addition, "%ld", number);
    if (0 < strlen(response->body)) {
        strcat(response->body, " ");
    }
    strcat(response->body, addition);

    // append new line
    response->body[strlen(response->body)] = '\n';
}
