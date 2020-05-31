FLAGS = -c -Wall -Werror -Wextra -std=c99 -g
ITREE = ../itree/itree
PILA_COLA = ../pila_cola/pila_cola

interprete: interprete.c itree.o 
	gcc -o interprete interprete.c itree.o 

itree.o: $(ITREE).c $(ITREE).h
	gcc $(FLAGS) $(ITREE).c

#pila_cola.o: $(PILA_COLA).c $(PILA_COLA).h
	#gcc $(FLAGS) $(PILA_COLA).c