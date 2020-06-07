FLAGS = -c -Wall -Werror -Wextra -std=c99 -g
ITREE = ../itree/itree
COLA = ../itree/cola/cola

interprete: interprete.c itree.o 
	gcc -o interprete interprete.c itree.o 

itree.o: $(ITREE).c $(ITREE).h
	gcc $(FLAGS) $(ITREE).c

#cola.o: $(COLA).c $(COLA).h
	#gcc $(FLAGS) $(COLA).c