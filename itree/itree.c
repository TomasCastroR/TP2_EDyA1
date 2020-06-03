#include "itree.h"
#include <stdlib.h>
#include <stdio.h>


Intervalo* intervalo_crear (double extIzq, double extDer) {
  Intervalo *newIntervalo = malloc (sizeof(Intervalo));
  newIntervalo->extrIzq = extIzq;
  newIntervalo->extrDer = extDer;
  return newIntervalo;
}

int intervalo_igualdad (Intervalo *inter1, Intervalo *inter2) {
  return inter1->extrIzq == inter2->extrIzq && inter1->extrDer == inter2->extrDer;
}

int intervalo_no_intersecar (Intervalo *inter1, Intervalo *inter2) {
  return inter2->extrDer < inter1->extrIzq || inter1->extrDer < inter2->extrIzq;
}

ITree itree_crear() {
  return NULL;
}

void itree_destruir (ITree arbol) {
  if (arbol != NULL) {
    itree_destruir(arbol->izq);
    itree_destruir(arbol->der);
    free (arbol->intervalo);
    free (arbol);
  }
}

int itree_altura (ITree arbol) {
  if (arbol == NULL)
    return -1;
  else return arbol->altura;
}

int itree_balance_altura (ITree arbol) {
  return itree_altura (arbol->izq) - itree_altura (arbol->der);
}

ITree itree_rotar_derecha (ITree arbol) {
  arbol->altura -= 1;
  INodo *aux = arbol->izq->der;
  arbol->izq->der = arbol;
  INodo *aux2 = arbol->izq;
  arbol->izq = aux;
  arbol = aux2;
  return arbol;
}

ITree itree_rotar_izquierda (ITree arbol) {
  arbol->altura -= 1;
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
    int balanceAlturaIzq = itree_balance_altura (arbol->izq);
    if (balanceAlturaIzq == 1)
      arbol = itree_rotar_derecha (arbol);
    else arbol = itree_rotar_izq_der (arbol);
  }
  else {
    if (balanceAltura < -1) {
      int balanceAlturaDer = itree_balance_altura (arbol->der);
      if (balanceAlturaDer == -1)
        arbol = itree_rotar_izquierda (arbol);
      else arbol = itree_rotar_der_izq (arbol);
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
  double maximoExtDer;
  if (arbol->der == NULL && arbol->izq == NULL)
    arbol->maxExtremoDer = arbol->intervalo->extrDer;
  else {
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
  }
  return arbol;
}

ITree itree_insertar (ITree arbol, Intervalo *intervalo) {
  if (arbol == NULL) {
    arbol = malloc (sizeof(INodo));
    arbol->intervalo = intervalo;
    arbol->maxExtremoDer = intervalo->extrDer;
    arbol->altura = 0;
    arbol->der = NULL;
    arbol->izq = NULL;
  }
  else {
    if (arbol->intervalo->extrIzq < intervalo->extrIzq) {
      arbol->der = itree_insertar (arbol->der,intervalo);
      if (arbol->izq == NULL)
        arbol->altura += 1;
    }
    else {
      if (arbol->intervalo->extrIzq > intervalo->extrIzq) {
        arbol->izq = itree_insertar (arbol->izq, intervalo);
        if (arbol->der == NULL)
          arbol->altura += 1;
      }
      else {
        if (arbol->intervalo->extrDer < intervalo->extrDer) {
          arbol->der = itree_insertar (arbol->der,intervalo);
          if (arbol->izq == NULL)
            arbol->altura += 1;
        }
        else {
          arbol->izq = itree_insertar (arbol->izq, intervalo);
          if (arbol->der == NULL)
            arbol->altura += 1;
        }
      }
    }
  }
  arbol = itree_chequeo_balancear (arbol);
  arbol = itree_max_extremo_der (arbol);
  return arbol;
}

void itree_eliminar (ITree arbol, Intervalo *intervalo);

int itree_contiene (ITree arbol, Intervalo *intervalo) {
  if (arbol == NULL)
    return 0;
  if (intervalo_igualdad (arbol->intervalo, intervalo))
    return 1;
  else {
    if (arbol->intervalo->extrIzq < intervalo->extrIzq)
      return itree_contiene (arbol->der, intervalo);
    else {
      if (arbol->intervalo->extrIzq > intervalo->extrIzq)
        return itree_contiene (arbol->izq, intervalo);
      else {
        if (arbol->intervalo->extrDer < intervalo->extrDer)
          return itree_contiene (arbol->der, intervalo);
        else return itree_contiene (arbol->izq, intervalo);
      }
    }
  }
}

INodo* itree_intersecar (ITree arbol, Intervalo *intervalo) {
  if (arbol == NULL || arbol->maxExtremoDer < intervalo->extrIzq)//tendriamos q ver de q lo pregunte 1 sola vez a esto, por ende tendria q ser fuera de la funcion-
    return NULL;
  if (!intervalo_no_intersecar (arbol->intervalo, intervalo))
    return arbol;
  if (arbol->intervalo->extrIzq > intervalo->extrDer )
    return itree_intersecar(arbol->izq,intervalo);
  if (arbol->izq->maxExtremoDer == arbol->maxExtremoDer)
      return itree_intersecar (arbol->izq, intervalo);
    else return itree_intersecar (arbol->der, intervalo);
}

void imprimir_intervalo (void* dato) {
  ITree arbol = dato;
  printf ("[%lf, %lf] ", arbol->intervalo->extrIzq, arbol->intervalo->extrDer);
}

void itree_recorrer_dfs (ITree arbol, FuncionVisitante funcion) {
  if (arbol == NULL)
    return;
  itree_recorrer_dfs (arbol->izq, funcion);
  funcion (arbol);
  itree_recorrer_dfs (arbol->der, funcion);
}

void itree_recorrer_bfs (ITree arbol, FuncionVisitante funcion);