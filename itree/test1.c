#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
  ITree arbol = itree_crear();
  Intervalo *intervalo;
  double izquierdo, derecho;
  for (int i = 0; i < 3; ++i) {
    printf ("ingrese un intervalo:");
    scanf ("%lf, %lf", &izquierdo, &derecho);
    intervalo = intervalo_crear (izquierdo, derecho);
    arbol = itree_insertar (arbol, intervalo);
  }
  itree_recorrer_dfs (arbol, imprimir_intervalo);
  printf ("La raiz es: [%lf, %lf]", arbol->intervalo->extrIzq, arbol->intervalo->extrDer);
  itree_destruir (arbol);
}