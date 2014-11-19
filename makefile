CC=clang
CFLAGS=-Wall -Wextra -pedantic -ggdb3 -std=c99

all: _objdir _maw _mal
	$(CC) $(CFLAGS) obj/maw.o obj/mal.o -o maw

_maw: _objdir
	$(CC) $(CFLAGS) -c src/maw.c -o obj/maw.o

_mal: _objdir
	$(CC) $(CFLAGS) -c src/mal.c -o obj/mal.o

test:
	@$(CC) $(CFLAGS) src/mal.c src/test.c -o test
	@./test
	@rm test

test_gdb:
	@$(CC) $(CFLAGS) src/mal.c src/test.c -o test
	@gdb test
	@rm test

_objdir:
	mkdir -p obj
