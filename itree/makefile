FLAGS = -c -Wall -Werror -Wextra -std=c99 -g
COLA = cola/cola

testitre: test1.c itree.o intervalo.o cola.o
	gcc -o testitree test1.c itree.o intervalo.o cola.o

itree.o: itree.c itree.h
	gcc $(FLAGS) itree.c

intervalo.o: intervalo.c intervalo.h
	gcc $(FLAGS) intervalo.c

cola.o: $(COLA).c $(COLA).h
	gcc $(FLAGS) $(COLA).c