#include "funcionesInterprete.h"
#include <stdio.h>

int main () {
  ITree arbol = itree_crear();
  char comando[100];
  int idComando, CONDICION = 1;
  imprimir_menu ();
  while (CONDICION) {
    printf ("Ingrese un comando:");
    scanf ("%[^\n]", comando);
    getchar ();
    idComando = validar_comando (comando);
    ejecutar_comando (idComando, comando, &arbol, &CONDICION);
  }
}