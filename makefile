all: main matr
	clang obj/main.o obj/matr.o -o mar

main:
	clang -Wall -c -std=c99 src/main.c -o obj/main.o

matr:
	clang -Wall -c -std=c99 src/matr.c -o obj/matr.o
