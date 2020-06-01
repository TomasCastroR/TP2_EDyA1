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

int itree_altura (ITree arbol) {
  if (arbol == NULL)
    return -1;
  else {
    int alturaLeft = itree_altura (arbol->izq);
    int alturaRight = itree_altura (arbol->der);
    if (alturaLeft > alturaRight)
      return alturaLeft + 1;
    else return alturaRight + 1;
  }
}

int itree_balance_altura (ITree arbol) {
  return itree_altura (arbol->izq) - itree_altura (arbol->der);
}

ITree itree_rotar_derecha (ITree arbol) {
  INodo *aux = arbol->izq->der;
  arbol->izq->der = arbol;
  INodo *aux2 = arbol->izq;
  arbol->izq = aux;
  arbol = aux2;
  return arbol;
}

ITree itree_rotar_izquierda (ITree arbol) {
  INodo *aux = arbol->der->izq;
  arbol->der->izq = arbol;
  INodo *aux2 = arbol->der;
  arbol->der = aux;
  arbol = aux2;
  return arbol;
}

ITree itree_rotar_izq_der (ITree arbol) {
  arbol->izq = itree_rotar_izquierda (arbol->izq);
  arbol = itree_rotar_derecha (arbol);
  return arbol;
}

ITree itree_rotar_der_izq (ITree arbol) {
  arbol->der = itree_rotar_derecha (arbol->der);
  arbol = itree_rotar_izquierda (arbol);
  return arbol;
}

ITree itree_chequeo_balancear (ITree arbol) {
  int balanceAltura = itree_balance_altura (arbol);
  if (balanceAltura > 1) {
    int balanceAlturaIzq = itree_balance_altura(arbol->izq);
    if (balanceAlturaIzq > 1)
      arbol = itree_rotar_derecha(arbol);
    else {
      if (balanceAlturaIzq < -1)
        arbol = itree_rotar_izq_der (arbol);
    }
  }
  else {
    if (balanceAltura < -1) {
      int balanceAlturaDer = itree_balance_altura(arbol->der);
      if (balanceAlturaDer > 1)
        arbol = itree_rotar_derecha(arbol);
      else {
        if (balanceAlturaDer < -1)
          arbol = itree_rotar_der_izq (arbol);
      }
    }
  }
  return arbol;
}
double mayor (double a, double b) {
  double mayor;
  if (a > b)
    mayor = a;
  else mayor = b;
  return mayor;
}

ITree itree_max_extremo_der (ITree arbol) {
  int maximoExtDer;
  if (arbol->der != NULL && arbol->izq != NULL) {
    maximoExtDer = mayor (arbol->der->maxExtremoDer, arbol->izq->maxExtremoDer);
    maximoExtDer = mayor (maximoExtDer, arbol->maxExtremoDer);
    arbol->maxExtremoDer = maximoExtDer;
  }
  else {
    if (arbol->der != NULL) {
      maximoExtDer = mayor (arbol->der->maxExtremoDer, arbol->maxExtremoDer);
      arbol->maxExtremoDer = maximoExtDer;
    }
    else {
      maximoExtDer = mayor (arbol->izq->maxExtremoDer, arbol->maxExtremoDer);
      arbol->maxExtremoDer = maximoExtDer;
    }
  }
  return arbol;
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
  arbol = itree_chequeo_balancear (arbol);
  // modificar maximo derecho
  arbol = itree_max_extremo_der (arbol);
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