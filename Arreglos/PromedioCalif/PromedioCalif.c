#include "locale.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

/*
 * Este programa ejemplifica el uso de funciones y procedimientos con valores
 * locales y arreglos Autor: Ordaz Magos Juan Pablo Fecha: 26-02-2025 v: 5.0
 */

float calificaciones[3];
float calificacion;
int opcion;
bool vacio = true;

// Declaración de procedimientos y funciones
void validaCalif(int CuentaCalif, float calificacion) {
  while (calificacion < 0 || calificacion > 10) {
    printf("\n La calificación digita es erronea");
    printf("\n Solo se aceptan valores entre 0 y 10");
    printf("\n Digita nuevamente la calificación: ");
    scanf("%f", &calificacion);
    calificaciones[CuentaCalif] = calificacion;
  }
}

void capturaCalif() {
  int CuentaCalif;
  for (CuentaCalif = 0; CuentaCalif <= 2; CuentaCalif++) {
    printf("\nCalificación [%i]: ", CuentaCalif);
    scanf("%f", &calificacion);
    calificaciones[CuentaCalif] = calificacion;
    validaCalif(CuentaCalif, calificaciones[CuentaCalif]);
  }
  vacio = false;
}

void verDatos() {
  int i;
  printf("\n");
  for (i = 0; i <= 2; i++) {
    printf("[%.2f] ", calificaciones[i]);
  }
}

void cambiarCalif() {
  int i;
  float calificacion;
  do {
    printf("\n¿Que calificación deseas cambiar?: ");
    scanf("%f", &calificacion);
    if (calificacion < 0 || calificacion > 2) {
      printf("[ERROR] - Ingresa un valor adecuado")
    }
  } while (calificacion < 0 || calificacion > 2);
}

void verProm(float promedio) { printf("\nPromedio: %.2f", promedio); }

float calcular() {
  static float suma;
  static int index;
  static float promedio;
  suma = 0;
  for (index = 0; index <= 2; index++) {
    suma += calificaciones[index];
  }
  promedio = suma / 3;
  return promedio;
}

int opcionMenu() {
  do {
    printf("\n\n\t\tMenu de opciones");
    printf("\n1. Captura de calificaciones");
    printf("\n2. Ver datos");
    printf("\n3. Calcular promedio");
    printf("\n4. Cambiar calificación");
    printf("\n5. Salir");
    printf("\n\nSelecciona una opcion: ");
    scanf("%d", &opcion);
    if (opcion < 1 || opcion > 5) {
      printf("\nOpcion no valida, intenta de nuevo.");
    }
  } while (opcion < 1 || opcion > 5);
  return opcion;
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  float acumulador, promedio;
  do {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    opcion = opcionMenu();
    switch (opcion) {
    case 1:
      capturaCalif();
      break;
    case 2:
      if (vacio == true) {
        printf("\nNo hay calificaciones capturadas.");
      } else {
        printf("\nCalificaciones capturadas: ");
        verDatos();
      }
      break;
    case 3:
      if (vacio == true) {
        printf("\nNo hay calificaciones capturadas.");
      } else {
        printf("\nPromedio: ");
        promedio = calcular();
        verProm(promedio);
      }
      break;
    case 4:
      if (vacio == true) {
        printf("\nNo hay calificaciones capturadas.");
      } else {
        printf("\nCambiar calificación: ");
        cambiarCalif();
      }
      break;
    case 5:
      printf("\nAdiós!!!!!!!!!.");
      break;
    default:
      printf("\nOpcion no valida, intenta de nuevo.");
      break;
    }
  } while (opcion != 5);
  return EXIT_SUCCESS;
}
