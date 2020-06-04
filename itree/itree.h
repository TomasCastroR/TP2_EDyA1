#ifndef __ITREE_H__
#define __ITREE_H__

#include "intervalo.h"

typedef struct _INodo {
  Intervalo* intervalo;
  double maxExtremoDer;
  struct _INodo* der;
  struct _INodo* izq;
}INodo;

typedef INodo* ITree;

typedef void (*FuncionVisitante) (ITree dato);

ITree itree_crear();

int itree_vacio (ITree arbol);

void itree_destruir (ITree arbol);

int itree_contiene (ITree arbol, Intervalo *intervalo);

ITree itree_insertar (ITree arbol, Intervalo *intervalo);

ITree itree_eliminar (ITree arbol, Intervalo *intervalo);

ITree itree_eliminar_nodo (ITree arbol);

void itree_destruir_nodo (ITree arbol);

INodo* itree_intersecarP (ITree arbol, Intervalo *intervalo);

INodo* itree_intersecar (ITree arbol, Intervalo *intervalo);

void itree_recorrer_dfs (ITree arbol, FuncionVisitante funcion);

void itree_recorrer_bfs (ITree arbol, FuncionVisitante funcion);

int itree_altura (ITree arbol);

int itree_balance_altura (ITree arbol);

ITree itree_chequeo_balancear (ITree arbol);

ITree itree_rotar_derecha (ITree arbol);

ITree itree_rotar_izquierda (ITree arbol);

ITree itree_rotar_der_izq (ITree arbol);

ITree itree_rotar_izq_der (ITree arbol);

ITree itree_max_extremo_der (ITree arbol);

void imprimir_intervalo (ITree dato);

double mayor (double a, double b);

void print2DUtil (ITree root, int space, FuncionVisitante funcion);

void print2D (ITree root, FuncionVisitante funcion);

#endif