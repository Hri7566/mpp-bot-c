#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

typedef struct {
	char _id[24];
	char name[40];
	char color[7];
} Participant;

char* getTest(void) {
	char* test = "test";
	return test;
}

char* getData(char* _id) {
	printf("%s\n", _id);
	return _id;
}

char* handleCommand(char* _id, char* name, char* color, char* message) {
	Participant* p = malloc(sizeof(Participant));

	strcpy(p->_id, _id);
	strcpy(p->name, name);
	strcpy(p->color, color);

	char* out;
	char* arg;
	arg = strtok(message, " ");
	int len = getCommandsLength();

	for (int i = 0; i < len; i++) {
		// printf("%d: %s, %s\n", i, arg, commands[i].id);
		if (strcmp(arg, commands[i].id) == 0) {
			out = (*(commands[i].callback))();
			break;
		}
	}

	return out;
}
