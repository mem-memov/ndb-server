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
    }

    if (1 == Request_isCommand(requestContainer, "read")) {
        printf("2");
    }

    if (1 == Request_isCommand(requestContainer, "connect")) {
        printf("3");
    }

/*
    int numberCount = 0;
    for (i = 0; i < requestLength; i++) {
        if (request[i] = ' ') {
            numberCount++;
        }
    }
    if (numberCount > 0) {
        numberCount++;
    }

    long int numbers[numberCount];

    if (0 == numberCount) {
        long int id = ndb_create();
    }

    if (2 == numberCount) {
        int length = 4096;
        long int buffer[length];
        int offset = 0;
        long int total = ndb_read(1, buffer, length, offset);
    }

    if (3 == numberCount) {
        ndb_connect(1, 3);
    }
*/
    int responseLength = 10;
    return responseLength;
}
