#ifndef __COLA_H__
#define __COLA_H__

#define MAX_COLA 64

typedef struct {
  void* datos[MAX_COLA];
  int primero;
  int ultimo;
}Cola;

Cola* cola_crear();

int cola_vacio (Cola* cola);

void cola_destruir (Cola* cola);

void cola_encolar (Cola **cola, void* dato);

void* cola_primero (Cola *cola);

void cola_desenColar (Cola **cola);

#endif