#ifndef ERROR_HEADER
#define ERROR_HEADER

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
void Error_whileApplicationExecutingWithSmallBuffer(int bufferLength, long int total);

void Error_whileRequestConstructingWithMaxLength(int maxLength);
void Error_beforeRequestFinishedCheck(char endCharacter);
void Error_beforeRequestCommandCheck(char endCharacter);
void Error_beforeRequestGettingArgument(char endCharacter);
void Error_afterRequestGettingArgument(char isFound, int orderNumber);

void Error_whileResponseConstructingWithMaxLength(int maxLength);
void Error_beforeResponseLength(char endCharacter);
void Error_beforeResponseAddingNumber(char endCharacter);

#endif
