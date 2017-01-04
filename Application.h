#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include "Request.h"
#include "Response.h"

struct Application {

};

struct Application * Application_construct();

void Application_destruct(struct Application * application);

void Application_execute(struct Application * application, struct Request * request, struct Response * response);

#endif
