all: main mal
	clang obj/main.o obj/mal.o -o mac

main:
	clang -Wall -c -std=c99 src/main.c -o obj/main.o

mal:
	clang -Wall -c -std=c99 src/mal.c -o obj/mal.o
