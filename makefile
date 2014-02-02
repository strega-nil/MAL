all: _maw _mal
	clang obj/maw.o obj/mal.o -o maw

_maw:
	clang -Wall -Werror -ggdb3 -c -std=c99 src/maw.c -o obj/maw.o

_mal:
	clang -Wall -Werror -ggdb3 -c -std=c99 src/mal.c -o obj/mal.o
