#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

#define COUNT 10



ITree itree_crear() {
  return NULL;
}

int itree_vacio (ITree arbol) {
  return arbol == NULL;
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
int mayor_int (int a, int b) {
  if (a > b)
    return a;
  else return b;
}
ITree itree_actualizar_altura_der (ITree arbol) {
  if (arbol->izq == NULL)
    arbol->altura += 1;
  else arbol->altura = mayor_int (arbol->der->altura + 1, arbol->izq->altura);
  return arbol;
}
ITree itree_actualizar_altura_izq (ITree arbol) {
  if (arbol->der == NULL)
    arbol->altura += 1;
  else arbol->altura = mayor_int (arbol->izq->altura + 1, arbol->der->altura);
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
    if (arbol->intervalo->extrIzq < intervalo->extrIzq) {
      arbol->der = itree_insertar (arbol->der, intervalo);
    }
    else {
      if (arbol->intervalo->extrIzq > intervalo->extrIzq) {
        arbol->izq = itree_insertar (arbol->izq, intervalo);
      }
      else {
        if (arbol->intervalo->extrDer < intervalo->extrDer) {
          arbol->der = itree_insertar (arbol->der, intervalo);
        }
        else {
          if (arbol->intervalo->extrDer > intervalo->extrDer) {
            arbol->izq = itree_insertar (arbol->izq, intervalo);
          }
          else return arbol;
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

INodo* itree_intersecarP (ITree arbol, Intervalo *intervalo) {
  if (arbol == NULL)
    return NULL;
  if (!intervalo_no_intersecar (arbol->intervalo, intervalo))
    return arbol;
  if (!itree_vacio (arbol->izq) && arbol->izq->maxExtremoDer >= intervalo->extrIzq)
    return itree_intersecarP (arbol->izq, intervalo);
  else return itree_intersecarP (arbol->der, intervalo);
}

INodo* itree_intersecar (ITree arbol, Intervalo *intervalo) {
  if (arbol != NULL) {
    if (arbol->maxExtremoDer < intervalo->extrIzq)
      return NULL;
    else return itree_intersecarP (arbol, intervalo);
  }
  else return NULL;
}

void imprimir_intervalo (void* dato) {
  ITree arbol = dato;
  printf ("[%lf, %lf]", arbol->intervalo->extrIzq, arbol->intervalo->extrDer);
}

void print2DUtil (ITree root, int space, FuncionVisitante funcion) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->der, space, funcion); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    funcion(root); 
  
    // Process left child 
    print2DUtil(root->izq, space, funcion); 
}

void print2D (ITree root, FuncionVisitante funcion) {
  print2DUtil (root, 0, funcion);
}

void itree_recorrer_dfs (ITree arbol, FuncionVisitante funcion) {
  if (arbol == NULL)
    return;
  itree_recorrer_dfs (arbol->izq, funcion);
  funcion (arbol);
  itree_recorrer_dfs (arbol->der, funcion);
}

void itree_recorrer_bfs (ITree arbol, FuncionVisitante funcion);