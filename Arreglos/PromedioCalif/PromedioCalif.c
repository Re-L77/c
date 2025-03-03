#include "locale.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

/*
 * Este programa ejemplifica el uso de funciones y procedimientos con valores
 * locales y arreglos Autor: Ordaz Magos Juan Pablo Fecha: 26-02-2025 v: 3.0
 */

void capturaCalif();
void validaCalif(int CuentaCalif, float calificacion);
void verDatos();
float calcular();
void verProm(float promedio);

float calificaciones[3];
float calificacion;

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  char resp;
  float acumulador, promedio;
  do {
    system("clear");
    capturaCalif();
    promedio = calcular();
    verDatos();
    verProm(promedio);
    printf("\n¿Deseas calcular otro promedio?: ");
    fflush(stdin);
    scanf(" %c", &resp);
  } while (resp == 's' || resp == 'S');
  return EXIT_SUCCESS;
}

void capturaCalif() {
  int CuentaCalif;
  for (CuentaCalif = 0; CuentaCalif <= 2; CuentaCalif++) {
    printf("\nCalificación [%i]: ", CuentaCalif);
    scanf("%f", &calificacion);
    calificaciones[CuentaCalif] = calificacion;
    validaCalif(CuentaCalif, calificaciones[CuentaCalif]);
  }
}

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

void verDatos() {
  int i;
  printf("\n");
  for (i = 0; i <= 2; i++) {
    printf("[%.2f] ", calificaciones[i]);
  }
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
