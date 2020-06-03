#ifndef __ITREE_H__
#define __ITREE_H__

typedef struct {
  double extrIzq;
  double extrDer;
}Intervalo;

typedef struct _INodo {
  Intervalo* intervalo;
  double maxExtremoDer;
  int altura;
  struct _INodo* der;
  struct _INodo* izq;
}INodo;

typedef INodo* ITree;

typedef void (*FuncionVisitante) (void* dato);

Intervalo* intervalo_crear (double extIzq, double extDer);

int intervalo_igualdad (Intervalo *inter1, Intervalo *inter2);

int intervalo_no_intersecar (Intervalo *inter1, Intervalo *inter2);

ITree itree_crear();

void itree_destruir (ITree arbol);

int itree_contiene (ITree arbol, Intervalo *intervalo);

ITree itree_insertar (ITree arbol, Intervalo *intervalo);

void itree_eliminar (ITree arbol, Intervalo *intervalo);

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

void imprimir_intervalo (void* dato);

double mayor (double a, double b);

#endif