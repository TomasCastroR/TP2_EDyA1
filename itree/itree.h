#ifndef __ITREE_H__
#define __ITREE_H__

#include "intervalo/intervalo.h"

typedef struct _INodo {
  Intervalo* intervalo;
  double maxExtremoDer;
  struct _INodo* der;
  struct _INodo* izq;
}INodo;

typedef INodo* ITree;

typedef void (*FuncionVisitante) (ITree dato);
/* itree_crear: -> ITree
Crea un arbol. */
ITree itree_crear();

/* itree_vacio: ITree -> int
Recibe un arbol y se fija si esta vacio o no.*/
int itree_vacio (ITree arbol);

/* itree_destruir: ITree -> 
Recibe un arbol y lo libera.*/
void itree_destruir (ITree arbol);

/* itree_insertar: ITree, Intervalo -> ITree
Recibe un arbol y un intervalo e inserta este intervalo en el arbol.*/
ITree itree_insertar (ITree arbol, Intervalo *intervalo);

/* itree_eliminar: ITree, Intervalo -> ITree
Recibe un arbol y un intervalo, si el intervalo se encuentra en el arbol
lo elimina.*/
ITree itree_eliminar (ITree arbol, Intervalo *intervalo);

/* itree_eliminar_nodo: ITree -> ITree
                  ¿?*/
ITree itree_eliminar_nodo (ITree arbol);

/* itree_destruir_nodo: ITree ->
Recibe el nodo de un arbol y lo libera.*/
void itree_destruir_nodo (ITree arbol);

/* itree_intersecarP: ITree, Intervalo -> *INodo
Recibe un arbol y un intervalo
Chequea si existe hay alguna interseccion entre el intervalo y algun nodo del arbol. */
INodo* itree_intersecarP (ITree arbol, Intervalo *intervalo);

/* itree_intersecar: ITree, Intervalo -> *INodo
Recibe un arbol y un intervalo
Contempla solo 1 caso en particular de la interseccion.*/
INodo* itree_intersecar (ITree arbol, Intervalo *intervalo);

/* itree_recorre_dfs: ITree, FuncionVisitante -> 
Recibe un arbol y una funcion.
 Recorre el arbol utilizando el algoritmo dfs y lo va imprimiendo */
void itree_recorrer_dfs (ITree arbol, FuncionVisitante funcion);

/* itree_recorre_dfs: ITree, FuncionVisitante -> 
Recibe un arbol y una funcion.
 Recorre el arbol utilizando el algoritmo bfs y lo va imprimiendo */
void itree_recorrer_bfs (ITree arbol, FuncionVisitante funcion);

/* itree_altura: ITree -> int*/
int itree_altura (ITree arbol);

/* itree_balance_altura: ITree -> int
*/
int itree_balance_altura (ITree arbol);

/* itree_chequeo_balancear: ITree -> ITree
*/
ITree itree_chequeo_balancear (ITree arbol);

ITree itree_rotar_derecha (ITree arbol);

ITree itree_rotar_izquierda (ITree arbol);

ITree itree_rotar_der_izq (ITree arbol);

ITree itree_rotar_izq_der (ITree arbol);

ITree itree_max_extremo_der (ITree arbol);

void imprimir_intervalo (ITree dato);

double mayor (double a, double b);

#endif