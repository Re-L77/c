#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Programa que calcula el escalar de un matriz
 * Fecha: 03/05/2025
 * V: 1.0
 */

float datos[4][3];
bool valido = false;

void capturar() {
  static int fila;
  static int col;
  static int cont;
  cont = 1;
  for (fila = 0; fila < 4; fila++) {
    for (col = 0; col <= 2; col++) {
      printf("Número [%d][%d] :", fila, col);
      scanf("%f", &datos[fila][col]);
    }
  }
  valido = true;
}

void verD() {
  if (valido == true) {
    for (int fila = 0; fila <= 3; fila++) {
      for (int col = 0; col <= 2; col++) {
        printf("[%f] ", datos[fila][col]);
      }
      printf("\n");
    }
  } else {
    printf("[ERROR] - Matriz vacía.\n");
  }
}

void multiplica() {
  static float res[4][3];
  static float escalar;
  if (valido == true) {
    printf("Digite escalar: ");
    scanf("%f", &escalar);
    for (int fila = 0; fila <= 3; fila++) {
      for (int col = 0; col <= 2; col++) {
        res[fila][col] = datos[fila][col] * escalar;
        printf("[%f] ", res[fila][col]);
      }
      printf("\n");
    }
  } else {
    printf("[ERROR] - Matriz vacía.\n");
  }
}

int main(int argc, char *argv[]) {
  char resp;
  int opc;
  system("clear");
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
      system("clear");
      verD();
      break;
    case 3:
      system("clear");
      multiplica();
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
