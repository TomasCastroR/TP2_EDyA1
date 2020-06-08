FLAGS = -c -Wall -Werror -Wextra -std=c99 -g
ITREE = ../itree/itree
INTERVALO = ../itree/intervalo
COLA = ../itree/cola/cola

interprete: interprete.c itree.o cola.o intervalo.o funcionesInterprete.o
	gcc -o interprete interprete.c itree.o cola.o intervalo.o funcionesInterprete.o

funcionesInterprete.o: funcionesInterprete.c funcionesInterprete.h
	gcc $(FLAGS) funcionesInterprete.c

itree.o: $(ITREE).c $(ITREE).h
	gcc $(FLAGS) $(ITREE).c

cola.o: $(COLA).c $(COLA).h
	gcc $(FLAGS) $(COLA).c

intervalo.o: $(INTERVALO).c $(INTERVALO).h
	gcc $(FLAGS) $(INTERVALO).c