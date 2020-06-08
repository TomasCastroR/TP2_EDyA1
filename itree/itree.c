#include "itree.h"
#include "cola/cola.h"
#include <stdlib.h>
#include <stdio.h>

ITree itree_crear() {
  return NULL;
}

int itree_vacio (ITree arbol) {
  return arbol == NULL;
}

void itree_destruir (ITree arbol) {
  if (!itree_vacio (arbol)) {
    itree_destruir(arbol->izq);
    itree_destruir(arbol->der);
    itree_destruir_nodo (arbol);
  }
}

void itree_destruir_nodo (ITree arbol) {
  free (arbol->intervalo);
  free (arbol);
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
  if (itree_vacio (arbol))
    return 0;
  else return itree_altura (arbol->izq) - itree_altura (arbol->der);
}

ITree itree_rotar_derecha (ITree arbol) {
  INodo *aux = arbol->izq->der;
  arbol->izq->der = arbol;
  INodo *aux2 = arbol->izq;
  arbol->izq = aux;
  arbol = aux2;
  arbol->der = itree_max_extremo_der (arbol->der);
  return arbol;
}

ITree itree_rotar_izquierda (ITree arbol) {
  INodo *aux = arbol->der->izq;
  arbol->der->izq = arbol;
  INodo *aux2 = arbol->der;
  arbol->der = aux;
  arbol = aux2;
  arbol->izq = itree_max_extremo_der (arbol->izq);
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
    int balanceAlturaIzq = itree_balance_altura (arbol->izq);
    if (balanceAlturaIzq == 1)
      arbol = itree_rotar_derecha (arbol);
    else arbol = itree_rotar_izq_der (arbol);
  }
  else {
    if (balanceAltura < -1) {
      int balanceAlturaDer = itree_balance_altura (arbol->der);
      if (balanceAlturaDer == -1) {
        arbol = itree_rotar_izquierda (arbol);
      }
      else {
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
  if (!itree_vacio (arbol)) {
    double maximoExtDer;
    if (itree_vacio (arbol->izq) && itree_vacio (arbol->der))
      arbol->maxExtremoDer = arbol->intervalo->extrDer;
    else {
      if (!itree_vacio (arbol->izq) && !itree_vacio (arbol->der)) {
        maximoExtDer = mayor (arbol->der->maxExtremoDer, arbol->izq->maxExtremoDer);
        maximoExtDer = mayor (maximoExtDer, arbol->maxExtremoDer);
        arbol->maxExtremoDer = maximoExtDer;
      }
      else {
        if (!itree_vacio (arbol->der)) {
          maximoExtDer = mayor (arbol->der->maxExtremoDer, arbol->maxExtremoDer);
          arbol->maxExtremoDer = maximoExtDer;
        }
        else {
          maximoExtDer = mayor (arbol->izq->maxExtremoDer, arbol->maxExtremoDer);
          arbol->maxExtremoDer = maximoExtDer;
        }
      }
    }
  }
  return arbol;
}

ITree itree_insertar (ITree arbol, Intervalo *intervalo) {
  if (itree_vacio (arbol)) {
    arbol = malloc (sizeof(INodo));
    arbol->intervalo = intervalo;
    arbol->maxExtremoDer = intervalo->extrDer;
    arbol->der = NULL;
    arbol->izq = NULL;
  }
  else {
    if (arbol->intervalo->extrIzq < intervalo->extrIzq)
      arbol->der = itree_insertar (arbol->der, intervalo);
    else {
      if (arbol->intervalo->extrIzq > intervalo->extrIzq)
        arbol->izq = itree_insertar (arbol->izq, intervalo);
      else {
        if (arbol->intervalo->extrDer < intervalo->extrDer)
          arbol->der = itree_insertar (arbol->der, intervalo);
        else {
          if (arbol->intervalo->extrDer > intervalo->extrDer)
            arbol->izq = itree_insertar (arbol->izq, intervalo);
        }
      }
    }
  }
  arbol = itree_chequeo_balancear (arbol);
  arbol = itree_max_extremo_der (arbol);
  return arbol;
}

ITree itree_eliminar_nodo (ITree arbol) {
  INodo *aux;
  if (itree_vacio (arbol->der) && itree_vacio (arbol->izq)) {
    aux = arbol;
    arbol = NULL;
    itree_destruir_nodo (aux);
  }
  else {
    if (!itree_vacio (arbol->der) && !itree_vacio (arbol->izq)) {
      aux = arbol->der;
      for (; !itree_vacio (aux->izq); aux = aux->izq);
      Intervalo *sucesor = intervalo_crear (aux->intervalo->extrIzq, aux->intervalo->extrDer);
      arbol->der = itree_eliminar (arbol->der, aux->intervalo);
      free (arbol->intervalo);
      arbol->intervalo = sucesor;
      }
    else {
      if (!itree_vacio (arbol->der)) {
      aux = arbol;
      arbol = arbol->der;
      itree_destruir_nodo (aux);
      }
      else {
        aux = arbol;
        arbol = arbol->izq;
        itree_destruir_nodo (aux);
      }
    }
  }
  return arbol;
}

ITree itree_eliminar (ITree arbol, Intervalo *intervalo) {
  if (itree_vacio (arbol))
    return NULL;
  if (intervalo_igualdad (arbol->intervalo, intervalo))
    arbol = itree_eliminar_nodo (arbol);
  else {
    if (arbol->intervalo->extrIzq < intervalo->extrIzq)
      arbol->der = itree_eliminar (arbol->der, intervalo);
    else {
      if (arbol->intervalo->extrIzq > intervalo->extrIzq)
        arbol->izq = itree_eliminar (arbol->izq, intervalo);
      else {
        if (arbol->intervalo->extrDer < intervalo->extrDer)
          arbol->der = itree_eliminar (arbol->der, intervalo);
        else arbol->izq = itree_eliminar (arbol->izq, intervalo);
      }
    }
  }
  arbol = itree_chequeo_balancear (arbol);
  arbol = itree_max_extremo_der (arbol);
  return arbol;
}

INodo* itree_intersecarP (ITree arbol, Intervalo *intervalo) {
  if (arbol == NULL)
    return NULL;
  if (intervalo_intersecar (arbol->intervalo, intervalo))
    return arbol;
  if (!itree_vacio (arbol->izq) && arbol->izq->maxExtremoDer >= intervalo->extrIzq)
    return itree_intersecarP (arbol->izq, intervalo);
  else return itree_intersecarP (arbol->der, intervalo);
}

INodo* itree_intersecar (ITree arbol, Intervalo *intervalo) {
  if (!itree_vacio (arbol)) {
    if (arbol->maxExtremoDer < intervalo->extrIzq)
      return NULL;
    else return itree_intersecarP (arbol, intervalo);
  }
  else return NULL;
}

void imprimir_intervalo (ITree dato) {
  printf ("[%g, %g] ", dato->intervalo->extrIzq, dato->intervalo->extrDer);
}

void itree_recorrer_dfs (ITree arbol, FuncionVisitante funcion) {
  if (itree_vacio (arbol))
    return;
  itree_recorrer_dfs (arbol->izq, funcion);
  funcion (arbol);
  itree_recorrer_dfs (arbol->der, funcion);
}

void itree_recorrer_bfs (ITree arbol, FuncionVisitante funcion) {
  Cola *cola = cola_crear();
  cola_encolar (&cola, arbol);
  INodo *nodo;
  while (!cola_vacio (cola)) {
    nodo = cola_primero (cola);
    cola_desenColar (&cola);
    funcion (nodo);
    if (!itree_vacio (nodo->izq))
      cola_encolar (&cola, nodo->izq);
    if (!itree_vacio (nodo->der))
      cola_encolar (&cola, nodo->der);
  }
  cola_destruir (cola);
}
