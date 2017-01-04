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

void Application_execute(struct Application * application, struct Request * request, struct Response * response)
{
    if (1 == Request_isCommand(request, "create")) {
        long int id = ndb_create();
        Response_addNumber(response, id);
    }

    if (1 == Request_isCommand(request, "read")) {
        long int nodeId = Request_getArgument(request, 1);
        int length = 4096;
        long int buffer[length];
        int offset = 0;
        long int total = ndb_read(nodeId, buffer, length, offset);

        int i = 0;
        while (i < length && i < total) {
            Response_addNumber(response, buffer[i]);
            i++;
        }
    }

    if (1 == Request_isCommand(request, "connect")) {
        long int fromNodeId = Request_getArgument(request, 1);
        long int toNodeId = Request_getArgument(request, 2);
        ndb_connect(fromNodeId, toNodeId);
    }
}
