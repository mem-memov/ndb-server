#ifndef RESPONSE_HEADER
#define RESPONSE_HEADER

struct Response {
    char * body;
    int maxLength;
};

struct Response * Response_construct(int maxLength);

void Response_destruct(struct Response * response);

char * Response_body(struct Response * response);

int Response_length(struct Response * response);

void Response_clean(struct Response * response);

void Response_addNumber(struct Response * response, long int number);

void Response_addNumbers(struct Response * response, long int * buffer, long int bufferLength, long int total);

#endif
