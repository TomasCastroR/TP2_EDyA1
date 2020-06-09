#ifndef __COLA_H__
#define __COLA_H__

#define MAX_COLA 64

typedef struct {
  void* datos[MAX_COLA];
  int primero;
  int ultimo;
}Cola;

/* cola_crear: -> *Cola
Crea una cola*/
Cola* cola_crear();

/* cola_vacio: Cola* -> int
Recibe una cola y determina si esta vacia*/
int cola_vacio (Cola *cola);

/* cola_destruir: Cola*
Recibe una cola y la libera*/
void cola_destruir (Cola *cola);

/* cola_encolar: Cola**
Recibe una cola y un dato. Agrega el dato a la cola.*/
void cola_encolar (Cola **cola, void *dato);

/* cola_primero: Cola*
Recibe una cola y retorna el primer dato de la cola.*/
void* cola_primero (Cola *cola);

/* cola_desencolar: Cola**
Recibe una cola y le saca el primer dato*/
void cola_desencolar (Cola **cola);

#endif