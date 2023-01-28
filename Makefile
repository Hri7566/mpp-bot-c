SRCS := src/bot.c src/command.c

all:
	$(CC) -g -shared -fPIC -o ./bot.so $(SRCS) -Iinclude
