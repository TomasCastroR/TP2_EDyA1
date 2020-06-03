#include "intervalo.h"
#include <stdlib.h>

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