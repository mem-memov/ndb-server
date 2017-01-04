#include "Request.h"
#include <stdlib.h>
#include <string.h>

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
