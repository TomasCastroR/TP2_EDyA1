#include "funcionesInterprete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar_comando (char* comando) {
  int idComando;
  switch (comando[0]) {
    case 'i':
      if (validar_formato (comando))
        idComando = 0;
      else idComando = -1;
      break;
    case 'e':
      if (validar_formato (comando))
        idComando = 1;
      else idComando = -1;
      break;
    case '?':
      if (validar_formato (comando))
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

int validar_formato (char* comando) {
  return comando[1] == ' ' && comando[2] == '[';
}

Intervalo* validar_intervalo (char* comando) {
  Intervalo *intervalo = NULL;
  double izquierdo, derecho;
  char bufferIzq[100] = "", bufferDer[100] = "", *basura;
  int indice = 0, i = 3;
  for (; comando[i] != ','; ++i) {
    bufferIzq[indice] = comando[i];
    indice++;
  }
  bufferIzq[indice + 1] = '\0';
  izquierdo = strtod (bufferIzq, &basura);
  if (strcmp (bufferIzq, "") != 0 && strcmp (basura, "") == 0 && comando[i + 1] == ' ') {
    indice = 0;
    i += 2;
    for (; comando[i] != ']'; ++i) {
      bufferDer[indice] = comando[i];
      indice++;
    }
    bufferDer[indice + 1] = '\0';
    derecho = strtod (bufferDer, &basura);
    if (strcmp (bufferDer, "") != 0 && strcmp (basura, "") == 0 && comando[i + 1] == '\0')
      intervalo = intervalo_crear (izquierdo, derecho);
  }
  return intervalo;
}

void ejecutar_comando (int idComando, char* comando, ITree* arbol, int* condicion) {
  Intervalo *intervalo;
  switch (idComando) {
    case 0:
      intervalo = validar_intervalo (comando);
      if (intervalo != NULL)
        *arbol = itree_insertar (*arbol, intervalo);
      else printf ("INTERVALO INVALIDO\n");
      break;
    case 1:
      intervalo = validar_intervalo (comando);
      if (intervalo != NULL) {
        *arbol = itree_eliminar (*arbol, intervalo);
        free (intervalo);
      }
      else printf ("INTERVALO INVALIDO\n");
      break;
    case 2:
      intervalo = validar_intervalo (comando);
      if (intervalo != NULL) {
        INodo *nodo = itree_intersecar (*arbol, intervalo);
        if (nodo != NULL) {
          printf ("SI, ");
          imprimir_intervalo (nodo);
          printf ("\n");
        }
        else printf ("NO\n");
        free (intervalo);
      }
      else printf ("INTERVALO INVALIDO\n");
      break;
    case 3:
      itree_recorrer_dfs (*arbol, imprimir_intervalo);
      printf ("\n");
      break;
    case 4:
      itree_recorrer_bfs (*arbol, imprimir_intervalo);
      printf ("\n");
      break;
    case 5:
      itree_destruir (*arbol);
      *condicion = 0;
      break;
    default:
      printf ("COMANDO INEXISTENTE\n");
      break;
  }
}