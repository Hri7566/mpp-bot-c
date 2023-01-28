#include "command.h"

char* helpCallback() {
	// char helpMenu[512];
	// strcpy(helpMenu, "Commands: ");
	// printf("help menu: %s\n", helpMenu);
	// int len = getCommandsLength();
	// for (int i = 0; i < len; i++) {
	// 	printf("cur menu: %s | cur id: %s\n", helpMenu, commands[i].id);
	// 	strcat(helpMenu, commands[i].id);
	// }
	// printf("help menu: %s\n", helpMenu);

	// char* out;
	// strcpy(out, helpMenu);

	// return out;

	char* helpMenu = "Commands: chelp, cabout";

	return helpMenu;
}

char* aboutCallback() {
	return "This bot was written in C.";
}

Command commands[] = {
	{
		.id = "chelp",
		.callback = helpCallback
	},
	{
		.id = "cabout",
		.callback = aboutCallback
	},
	{
		.id = "_spec_term",
		.callback = NULL
	}
};

int getCommandsLength(void) {
	int len = 0;
	char** id;
	while (strcmp(*id, "_spec_term") != 0) {
		id = &commands[len].id;
		len++;
	}
	len--;
	return len;
}
