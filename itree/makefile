FLAGS = -c -Wall -Werror -Wextra -std=c99 -g

testitre: test1.c itree.o intervalo.o
	gcc -o testitree test1.c itree.o intervalo.o

itree.o: itree.c itree.h
	gcc $(FLAGS) itree.c

intervalo.o: intervalo.c intervalo.h
	gcc $(FLAGS) intervalo.c
