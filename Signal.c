#include "Signal.h"
#include <stdlib.h>
#include <stdio.h>

struct Signal * Signal_construct(int code, void (*handler)(int))
{
	struct Signal * signal = malloc(sizeof(struct Signal));

	signal->code = code;
	signal->handler = handler;

	return signal;
}

void Signal_destruct(struct Signal * signal)
{
    free(signal);
}

int Signal_catch(struct Signal * signal)
{
    struct sigaction action;
    action.sa_handler = signal->handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(signal->code, &action, NULL);
}
