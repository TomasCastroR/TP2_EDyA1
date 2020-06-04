#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
  ITree arbol = itree_crear();
  Intervalo *intervalo;
  double izquierdo, derecho;
  for (int i = 0; i < 3; ++i) {
    printf ("\ningrese un intervalo:");
    scanf ("%lf, %lf", &izquierdo, &derecho);
    intervalo = intervalo_crear (izquierdo, derecho);
    arbol = itree_insertar (arbol, intervalo);
    print2D (arbol, imprimir_intervalo);
  }
  /*itree_recorrer_dfs (arbol, imprimir_intervalo);
  intervalo = intervalo_crear (0.5, 0.75);
  INodo *nodo = itree_intersecar (arbol, intervalo);
  if (nodo) {
    printf ("SI INTERSECA\n");
    imprimir_intervalo (nodo);
  }
  else printf ("NO INTERSECA");*/
  itree_destruir (arbol);
}