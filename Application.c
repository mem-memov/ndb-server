#include "Application.h"
#include "Request.h"
#include "Response.h"
#include "Error.h"
#include <ndb.h>
#include <stdlib.h>

struct Application * Application_construct()
{
	struct Application * application = malloc(sizeof(struct Application));

	return application;
}

void Application_destruct(struct Application * application)
{
    free(application);
}

static void Application_create(struct Application * application, struct Request * request, struct Response * response)
{
    long int id = ndb_create();
    Response_addNumber(response, id);
}

static void Application_read(struct Application * application, struct Request * request, struct Response * response)
{
    long int nodeId = Request_getArgument(request, 1);
    int bufferLength = 4096;
    long int buffer[bufferLength];
    long int total = ndb_read(nodeId, buffer, bufferLength);

    Error_inApplicationWhileExecutingWithSmallBuffer(bufferLength, total);

    int i = 0;
    while (i < bufferLength && i < total)
    {
        Response_addNumber(response, buffer[i]);
        i++;
    }
}

static void Application_connect(struct Application * application, struct Request * request, struct Response * response)
{
    long int fromNodeId = Request_getArgument(request, 1);
    long int toNodeId = Request_getArgument(request, 2);
    ndb_connect(fromNodeId, toNodeId);
}

static void Application_intersect(struct Application * application, struct Request * request, struct Response * response)
{
    long int nodeCount = Request_countArguments(request);
    long int nodeIds[nodeCount];
    long int n;
    for (n = 0; n < nodeCount; n++) {
        nodeIds[n] = Request_getArgument(request, n+1);
    }
    int bufferLength = 4096;
    long int buffer[bufferLength];
    long int total = ndb_intersect(nodeIds, nodeCount, buffer, bufferLength);

    Error_inApplicationWhileExecutingWithSmallBuffer(bufferLength, total);

    int i = 0;
    while (i < bufferLength && i < total)
    {
        Response_addNumber(response, buffer[i]);
        i++;
    }
}

void Application_execute(struct Application * application, struct Request * request, struct Response * response)
{
    if (1 == Request_isCommand(request, "create"))
    {
        Application_create(application, request, response);
    }
    else if (1 == Request_isCommand(request, "read"))
    {
        Application_read(application, request, response);
    }
    else if (1 == Request_isCommand(request, "connect"))
    {
        Application_connect(application, request, response);
    }
    else if (1 == Request_isCommand(request, "intersect"))
    {
        Application_intersect(application, request, response);
    }
    else
    {
        Error_inApplicationWhileExecutingWithUnknownCommand();
    }
}
