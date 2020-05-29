FLAGS = -c -Wall -Werror -Wextra -std=c99 -g
AVL = ../avl/avl
PILA_COLA = ../pila_cola/pila_cola

interprete: interprete.c avl.o pila_cola.o
	gcc -o interprete interprete.c avl.o pila_cola.o

avl.o: $(AVL).c $(AVL).h
	gcc $(FLAGS) $(AVL).c

pila_cola.o: $(PILA_COLA).c $(PILA_COLA).h
	gcc $(FLAGS) $(PILA_COLA).c