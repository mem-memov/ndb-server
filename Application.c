#include "Application.h"
#include "Request.h"
#include "Response.h"
#include "Error.h"
#include <ndb.h>
#include <stdlib.h>

#include <stdio.h>

struct Application * Application_construct()
{
	struct Application * application = malloc(sizeof(struct Application));



	return application;
}

void Application_destruct(struct Application * application)
{
    free(application);
}

int Application_execute(struct Application * application, char * request, int requestLength, char * response, int maxResponseLength)
{
    struct Request * requestContainer = Request_construct(request, requestLength);
    struct Response * responseContainer = Response_construct(response, maxResponseLength);

    if (1 == Request_isCommand(requestContainer, "create")) {
        long int id = ndb_create();
        printf("%ld\n", id);
    }

    if (1 == Request_isCommand(requestContainer, "read")) {
        long int nodeId = Request_getArgument(requestContainer, 1);
        int length = 4096;
        long int buffer[length];
        int offset = 0;
        long int total = ndb_read(nodeId, buffer, length, offset);
        printf(" total: %ld\n", total);
        int i = 0;
        while (i < length && i < total) {
            if (i > 0) {
                printf(" ");
            }
            printf("%ld", buffer[i]);
            i++;
        }
        printf("\n");
    }

    if (1 == Request_isCommand(requestContainer, "connect")) {
        long int fromNodeId = Request_getArgument(requestContainer, 1);
        long int toNodeId = Request_getArgument(requestContainer, 2);
        printf("%ld->%ld\n", fromNodeId, toNodeId);
        ndb_connect(fromNodeId, toNodeId);
    }

    int responseLength = 10;
    return responseLength;
}
