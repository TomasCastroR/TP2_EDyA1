#ifndef __ITREE_H__
#define __ITREE_H__

typedef struct _INodo {
  double extremoIzq;
  double extremoDer;
  struct _INodo* der;
  struct _INodo* izq;
  double maxExtremoDer;
}INodo;
typedef enum {
  DERECHA,
  IZQUIERDA
}SentidoRotacion;

typedef INodo* ITree;

ITree itree_crear();

void itree_destruir (ITree arbol);

ITree itree_insertar (ITree arbol, double extIzq, double extDer);

void itree_eliminar (ITree arbol, double extIzq, double extDer);

INodo* itree_intersecar (ITree arbol, double extIzq, double extDer);

void itree_recorrer_dfs (ITree arbol);

void itree_recorrer_bfs (ITree arbol);

int itree_altura (ITree arbol, int alturaActual, int *alturaMax);

int itree_balance_altura (ITree arbol);

#endif