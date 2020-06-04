#ifndef __INTERVALO_H__
#define __INTERVALO_H__

typedef struct {
  double extrIzq;
  double extrDer;
}Intervalo;

Intervalo* intervalo_crear (double extIzq, double extDer);

int intervalo_igualdad (Intervalo *inter1, Intervalo *inter2);

int intervalo_intersecar (Intervalo *inter1, Intervalo *inter2);

#endif