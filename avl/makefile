FLAGS = -c -Wall -Werror -Wextra -std=c99 -g

testavl: test1.c avl.o
	gcc -o testavl test1.c avl.o

avl.o: avl.c avl.h
	gcc $(FLAGS) avl.c