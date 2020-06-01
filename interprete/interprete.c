#include "../itree/itree.h"
#include <stdio.h>


int main () {
  ITree arbol= itree_crear();
  char resto[10];
  int comando;
  double intervaloIzq, intervaloDer;
  int CONDICION = 1;
  printf ("ingrese un comando: ");
  scanf ("%[^\n]", resto);
  printf ("%c\n", resto[1]);
}