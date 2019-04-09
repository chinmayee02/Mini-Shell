CC=gcc

all:cayachi1_2b run

cayachi1_2b:cayachi1_2b.o
	gcc -o cayachi1_2b cayachi1_2b.c

run:cayachi1_2b	
	./cayachi1_2b

