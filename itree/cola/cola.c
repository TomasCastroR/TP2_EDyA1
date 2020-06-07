#include "cola.h"
#include <stdlib.h>
#include <assert.h>

Cola* cola_crear() {
  Cola *nuevaCola = malloc (sizeof (Cola));
  nuevaCola->primero = MAX_COLA - 1;
  nuevaCola->ultimo = MAX_COLA - 1;
  return nuevaCola;
}

int cola_vacio (Cola* cola) {
  return cola->primero == cola->ultimo;
}

void cola_destruir (Cola* cola) {
  free (cola);
}

void cola_encolar (Cola **cola, void* dato) {
  if ((*cola)->ultimo == MAX_COLA - 1)
    (*cola)->ultimo = 0;
  else (*cola)->ultimo += 1;
  assert ((*cola)->primero != (*cola)->ultimo);
  (*cola)->datos[(*cola)->ultimo] = dato;
}

void* cola_primero (Cola *cola) {
  if (cola->primero == MAX_COLA - 1)
    return cola->datos[0];
  else return cola->datos[cola->primero + 1];
}

void cola_desenColar (Cola **cola) {
  assert (!cola_vacio (*cola));
  if ((*cola)->primero == MAX_COLA - 1)
    (*cola)->primero = 0;
  else (*cola)->primero += 1;
}

void cola_imprimir (Cola *cola);
