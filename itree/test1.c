#include "itree.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
  ITree arbol = itree_crear();
  Intervalo *intervalo;
  double izquierdo, derecho;
  intervalo = intervalo_crear (5, 15);
  arbol = itree_insertar (arbol, intervalo);
  intervalo = intervalo_crear (0, 2);
  arbol = itree_insertar (arbol, intervalo);
  intervalo = intervalo_crear (17, 20);
  arbol = itree_insertar (arbol, intervalo);
  srand (time(NULL));
  for (int i = 0; i < 10; ++i) {
    izquierdo = rand() % 101;
    derecho = rand() % 101;
    while (izquierdo > derecho) {
      izquierdo = rand() % 101;
      derecho = rand() % 101;
    }
    intervalo = intervalo_crear (izquierdo, derecho);
    arbol = itree_insertar (arbol, intervalo);
  }
  print2D (arbol, imprimir_intervalo);
  intervalo = intervalo_crear (17, 20);
  arbol = itree_eliminar (arbol, intervalo);
  print2D (arbol, imprimir_intervalo);
  free (intervalo);
  itree_destruir (arbol);
}
