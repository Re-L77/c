#include <stdio.h>
#include <stdlib.h>

/*
 * Programa que calcula el escalar de un matriz
 * Fecha: 03/05/2025
 * V: 1.0
 */

float datos[4][3];

void capturar() {
  static int fila;
  static int col;
  static int cont = 1;
  for (fila = 0; fila < 4; fila++) {
    for (col = 0; col <= 2; col++) {
      datos[fila][col] = cont;
      cont++;
    }
  }
}
void verD() {}
void multiplica() {}

int main(int argc, char *argv[]) {
  char resp;
  int opc;
  do {
    printf("\nMENÚ\n");
    printf("\n 1- Capturar datos.");
    printf("\n 2- Ver datos.");
    printf("\n 3- Mutiplicar un escalar.");
    printf("\n 4- Salir.\n");
    printf("\nOpción: ");
    scanf("%d", &opc);
    switch (opc) {
    case 1:
      system("clear");
      capturar();
      printf("[HECHO] - Capturado con exito.\n");
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      printf("\n¡¡ADIÓS!!\n");
      break;
    default:
      system("clear");
      printf("\n[ERROR] - Ingresa un valor admitido [1-4]\n");
      break;
    }
  } while (opc != 4);
  return EXIT_SUCCESS;
}
