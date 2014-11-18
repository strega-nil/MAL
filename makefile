CC=clang
CFLAGS=-Wall -Wextra -pedantic -ggdb3 -std=c99

all: _maw _mal
	$(CC) $(CFLAGS) obj/maw.o obj/mal.o -o maw

_maw:
	$(CC) $(CFLAGS) -c src/maw.c -o obj/maw.o

_mal:
	$(CC) $(CFLAGS) -c src/mal.c -o obj/mal.o

test:
	$(CC) $(CFLAGS) src/mal.c src/test.c -o test
	./test
	rm test
