#ifndef __INTERVALO_H__
#define __INTERVALO_H__

typedef struct {
  double extrIzq;
  double extrDer;
}Intervalo;

/* intervalo_crear: double, double -> *Intervalo
Recibe dos doubles y devuelve el intervalo creado por ellos*/
Intervalo* intervalo_crear (double extIzq, double extDer);

/* intervalo_igualdad: Intervalo, Intervalo -> int
Recibe dos intervalos y determina si son iguales*/
int intervalo_igualdad (Intervalo *inter1, Intervalo *inter2);

/* intervalo_intersecar: Intervalo, Intervalo -> int
Recibe dos intervalos y determina si intersecan */
int intervalo_intersecar (Intervalo *inter1, Intervalo *inter2);

#endif