#include "../itree/itree.h"
#include <stdio.h>
#include <string.h>

int validar_comando (char* comando) {
  int primeraLetra = comando[0], segundaLetra = comando[1], terceraLetra = comando[2];
  int idComando;
  switch (primeraLetra) {
    case 'i':
      if (segundaLetra == ' ' && terceraLetra == '[')
        idComando = 0;
      else idComando = -1;
      break;
    case 'e':
      if (segundaLetra == ' ' && terceraLetra == '[')
        idComando = 1;
      else idComando = -1;
      break;
    case '?':
      if (segundaLetra == ' ' && terceraLetra == '[')
        idComando = 2;
      else idComando = -1;
      break;
    case 'd':
      if (strcmp (comando, "dfs") == 0)
        idComando = 3;
      else idComando = -1;
      break;
    case 'b':
      if (strcmp (comando, "bfs") == 0)
        idComando = 4;
      else idComando = -1;
      break;
    case 's':
      if (strcmp (comando, "salir") == 0)
        idComando = 5;
      else idComando = -1;
      break;
    default:
      idComando = -1;
      break;
  }
  return idComando;
}
void ejecutar_comando (int idComando, char* comando, ITree* arbol, int* condicion) {
  double intervaloIzq, intervaloDer;
  switch (idComando) {
    case '0':
      //validar intervalo
      //crear intervalo
      //ejecutar la funcion
      break;
    case '1':
      //validar intervalo
      //crear intervalo
      //ejecutar la funcion
      //liberar el intervalo
      break;
    case '2':
      //validar intervalo
      //crear intervalo
      //ejecutar la funcion
      //liberar el intervalo
      break;
    case '3':
      itree_recorrer_dfs (arbol, imprimir_intervalo);
      break;
    case '4':
      itree_recorrer_bfs (arbol, imprimir_intervalo);
      break;
    case '5':
      itree_destruir (arbol);
      *condicion = 0;
      break;
    default:
      printf ("COMANDO INEXISTENTE\n");
      break;
  }
}

int main () {
  ITree arbol = itree_crear();
  char comando[20];
  int idComando;
  int CONDICION = 1;
  while (CONDICION) {
    printf ("ingrese un comando: ");
    scanf ("%[^\n]", comando);
    idComando = validar_comando (comando);
    ejecutar_comando (idComando, comando, &arbol, &CONDICION);
  }
}