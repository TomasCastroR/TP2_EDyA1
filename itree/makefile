FLAGS = -c -Wall -Werror -Wextra -std=c99 -g

testitre: test1.c itree.o
	gcc -o testitree test1.c itree.o

itree.o: itree.c itree.h intervalo.o
	gcc $(FLAGS) itree.c intervalo.o

intervalo.o: intervalo.c intervalo.h
		gcc $(FLAGS) intervalo.c