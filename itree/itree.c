#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

ITree itree_crear() {
  return NULL;
}

void itree_destruir (ITree arbol) {
  if (arbol != NULL) {
    itree_destruir(arbol->izq);
    itree_destruir(arbol->der);
    free(arbol);
  }
}

int itree_altura (ITree arbol, int alturaActual, int *alturaMax) {
  if (arbol == NULL) {
    if (alturaActual > *alturaMax)
      *alturaMax = alturaActual;
  }
  else {
    alturaActual += 1;
    itree_altura (arbol->izq, alturaActual, alturaMax);
    itree_altura (arbol->der, alturaActual, alturaMax);   
  }
  return *alturaMax;
}

int itree_balance_altura (ITree arbol) {
  int *alturaMaxIzq = malloc (sizeof(int)), *alturaMaxDer = malloc (sizeof(int));
  *alturaMaxIzq = -1;
  *alturaMaxDer = -1;
  return itree_altura (arbol->izq, -1, alturaMaxIzq) - itree_altura (arbol->der, -1, alturaMaxDer);
}

ITree itree_insertar (ITree arbol, double extIzq, double extDer) {
  if (arbol == NULL) {
    arbol = malloc (sizeof(INodo));
    arbol->extremoIzq = extIzq;
    arbol->extremoDer = extDer;
    arbol->maxExtremoDer = extDer;
    arbol->der = NULL;
    arbol->izq = NULL;
  }
  else {
    if (arbol->extremoIzq < extIzq)
      arbol->der = itree_insertar (arbol->der, extIzq, extDer);
    else 
      arbol->izq = itree_insertar (arbol->izq, extIzq, extDer);
  }
  // balancear el arbol
  /*int balanceAltura = itree_balance_altura (arbol);
  if (balanceAltura > 1)
    itree_balancear (arbol->izq);
  else {
    if (balanceAltura < -1)
      itree_balancear (arbol->der);
  }*/
  // modificar maximo derecho
  return arbol;
}

void itree_eliminar (ITree arbol, double extIzq, double extDer);

INodo* itree_intersecar (ITree arbol, double extIzq, double extDer);

void itree_recorrer_dfs (ITree arbol) {
  if (arbol == NULL)
    return;
  itree_recorrer_dfs (arbol->izq);
  printf ("[%lf, %lf] ", arbol->extremoIzq, arbol->extremoDer);
  itree_recorrer_dfs (arbol->der);
}

void itree_recorrer_bfs (ITree arbol);