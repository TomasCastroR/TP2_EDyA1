#ifndef __FUNCIONESINTERPRETE_H__
#define __FUNCIONESINTERPRETE_H__

#include "../itree/itree.h"

void imprimir_menu ();

int validar_comando (char* comando);

int validar_formato (char* comando);

Intervalo* validar_intervalo (char* comando);

void ejecutar_comando (int idComando, char* comando, ITree* arbol, int* condicion);

#endif