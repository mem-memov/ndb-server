#include "Application.h"
#include "Error.h"
#include <ndb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

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
    int fileDescriptors[2];

    int pipeResult = pipe(fileDescriptors);
    Error_afterApplicationCreatingPipe(pipeResult);

    pid_t processId = fork();
    Error_afterApplicationForking((int)processId);

    if (0 == processId) { // child process code
        dup2(fileDescriptors[1], 1);
        close(fileDescriptors[0]);

        ndb_create();

        Error_afterApplicationExecuting();
    }

    dup2(fileDescriptors[0], 0);
    close(fileDescriptors[1]);

    int responseLength = 0;
    char character;
    do {
        character = fgetc(stdin);
        if(feof(stdin)) {
            break ;
        }
        responseLength++;
        Error_whileApplicationResponding(responseLength, maxResponseLength);
        response[responseLength - 1] = character;

    } while (1);

    return responseLength;
}
