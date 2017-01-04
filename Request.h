#ifndef REQUEST_HEADER
#define REQUEST_HEADER

struct Request {
    char * body;
};

struct Request * Request_construct(char * body, int length);

void Request_destruct(struct Request * request);

char Request_isCommand(struct Request * request, char * command);

#endif
