#ifndef SIGNAL_HEADER
#define SIGNAL_HEADER

struct Signal {
    int code;
    void (*handler)(int);
};

struct Signal * Signal_constructSigint(void (*handler)(int));

void Signal_destruct(struct Signal * signal);

int Signal_catch(struct Signal * signal);

#endif
