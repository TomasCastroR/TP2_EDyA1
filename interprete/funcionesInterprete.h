#ifndef __FUNCIONESINTERPRETE_H__
#define __FUNCIONESINTERPRETE_H__

#include "../itree/itree.h"

/* imprimir_menu:
Imprime los posibles comandos a utilizar del interprete*/
void imprimir_menu ();

/* validar_comando: char* -> int
Recibe un string. Se fija si el comando ingresado es valido y devuelve un numero
que representa la accion a tomar.*/
int validar_comando (char* comando);

/* validar_formato: char* -> int
Recibe un comando y valida si los siguientes 2 caracteres tienen el formato correcto. */
int validar_formato (char* comando);

/* validar_intervalo: char* -> Intervalo*
Recibe un comando, chequea si los extremos del intervalo son numeros y si el formato
del mismo es correcto.*/
Intervalo* validar_intervalo (char* comando);

/* ejecutar_comando: int, char*, ITree*, int* -> 
Recibe el idComando, el comando, un arbol y la condicion.
Dado el idcomando, ejecuta la accion correspondiente*/
void ejecutar_comando (int idComando, char* comando, ITree* arbol, int* condicion);

#endif