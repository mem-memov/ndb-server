#ifndef ERROR_HEADER
#define ERROR_HEADER

struct Error {
    char * message;
    int code;
};

struct Error * Error_construct(char * message, int code);

void Error_destruct(struct Error * error);

void Error_beforeListenerOpeningSocket(int listenerDescriptor);
void Error_afterListenerOpeningSocket(int listenerDescriptor);
void Error_beforeListenerBindingToPort(int listenerDescriptor);
void Error_afterListenerSettingSocketOption(int setSocketOptionResult);
void Error_afterListenerBindingToPort(int bindResult);
void Error_beforeListenerListening(int listenerDescriptor);
void Error_afterListenerListening(int listenResult);
void Error_beforeListenerAcceptingConnection(int listenerDescriptor);
void Error_afterListenerAcceptingConnection(int connectionDescriptor);

void Error_whileConnectionReceiving(int availableBufferLength);
void Error_afterConnectionSending(int sendResult);

void Error_afterServerForking(int processId);

void Error_afterApplicationCreatingPipe(int pipeResult);
void Error_afterApplicationForking(int processId);
void Error_whileApplicationResponding(int responseLength, int maxResponseLength);

#endif
