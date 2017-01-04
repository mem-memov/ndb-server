#include "Response.h"
#include <stdlib.h>

struct Response * Response_construct(char * buffer, int maxResponseLength)
{
	struct Response * response = malloc(sizeof(struct Response));

    response->buffer = buffer;
    response->maxResponseLength = maxResponseLength;

	return response;
}

void Response_destruct(struct Response * response)
{
    free(response);
}
