#ifndef REQUEST_HEADER
#define REQUEST_HEADER

struct Request {
    char * body;
    int maxLength;
};

struct Request * Request_construct(int maxLength);

void Request_destruct(struct Request * request);

char * Request_body(struct Request * request);

void Request_clean(struct Request * request);

int Request_maxLength(struct Request * request);

char Request_isFinished(struct Request * request);

char Request_isCommand(struct Request * request, char * command);

long int Request_getArgument(struct Request * request, int orderNumber);

long int Request_countArguments(struct Request * request);

void Request_getArguments(struct Request * request, long int * arguments, long int length);

char Request_isEmpty(struct Request * request);

#endif
