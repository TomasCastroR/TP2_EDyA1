FLAGS = -c -Wall -Werror -Wextra -std=c99 -g

testcola: test2.c cola.o
	gcc -o testcola test2.c cola.o

cola.o: cola.c cola.h
	gcc $(FLAGS) cola.c