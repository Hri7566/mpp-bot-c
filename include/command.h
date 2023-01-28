#ifndef _COMMAND_H
#define _COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* id;
	char* (*callback)(void);
} Command;

extern Command commands[];
int getCommandsLength(void);

#endif
