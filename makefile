all: div.o
	gcc -o main div.o
div.o: div.c
	gcc -c div.c
run: 
	./main