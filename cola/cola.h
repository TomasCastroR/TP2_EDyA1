#ifndef __COLA_H__
#define __COLA_H__

#define MAX_COLA 64

// typedef struct {
//   void* datos[MAX_COLA];
//   int primero;
//   int ultimo;
// }Cola;

typedef struct _SNodo{
  void *dato;
  struct _SNodo *sig;
} SNodo;

typedef struct _Cola {
  SNodo* primero;
  SNodo* ultimo;
} *Cola;

Cola queue_crear();

int queue_vacio (Cola queue);

void queue_destruir (Cola queue);

void queue_push (Cola *queue, void* dato);

void* queue_ultimo (Cola queue);

void queue_desenColar (Cola *queue);

void queue_imprimir (Cola queue);

#endif