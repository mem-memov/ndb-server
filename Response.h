#ifndef RESPONSE_HEADER
#define RESPONSE_HEADER

struct Response {
    char * buffer;
    int maxResponseLength;
};

struct Response * Response_construct(char * buffer, int maxResponseLength);

void Response_destruct(struct Response * response);

#endif
