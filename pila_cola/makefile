FLAGS = -c -Wall -Werror -Wextra -std=c99 -g

testpila_cola: test2.c pila_cola.o
	gcc -o testpila_cola test2.c pila_cola.o

pila_cola.o: pila_cola.c pila_cola.h
	gcc $(FLAGS) pila_cola.c