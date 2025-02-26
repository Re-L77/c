#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"

/*
 * Este programa ejemplifica el uso de funciones y procedimientos con valores locales
 * Autor: Ordaz Magos Juan Pablo
 * Fecha: 19-02-2025
*/

//Declaración de procedimientos y funciones
float validaCalif(float calif){
  while (calif < 0 || calif > 10) {
    printf("\n La calificación digita es erronea");
    printf("\n Solo se aceptan valores entre 0 y 10");
    printf("\n Digita nuevamente la calificación: ");
    scanf("%f", &calif);
  }
  return calif;
}

float pedirCalif() {
  //Variables locales
  int CuentaCalif;
  float calif, suma, califValida;
  suma=0;
  for (CuentaCalif = 1; CuentaCalif <= 3; CuentaCalif++) {
    printf("\nDigita la calificaión %i del alumno: ", CuentaCalif);
    scanf("%f", &calif);
    califValida = validaCalif(calif);
    suma += califValida;
  }
  return suma;
}

float calcularProm(float suma) {
  return suma / 3;
}

void mostrarRes(float promedio) {
  printf("\nEl promedio del alumno es: %.2f\n", promedio);
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  char resp;
  float acumulador, promedio;

  do {
    system("clear");
    acumulador = pedirCalif();
    promedio = calcularProm(acumulador);
    mostrarRes(promedio);
    printf("¿Deseas calcular otro promedio?\n");
    fflush(stdin);
    scanf(" %c", &resp);
  } while (resp == 's' || resp == 'S');
  return EXIT_SUCCESS;
}
