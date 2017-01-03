#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

struct Application {

};

struct Application * Application_construct();

void Application_destruct(struct Application * application);

int Application_execute(struct Application * application, char * request, int requestLength, char * response, int maxResponseLength);

#endif
