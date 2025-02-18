#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"

/*
 * Este programa ejemplifica el uso de funciones y procedimientos
 * Autor: Ordaz Magos Juan Pablo
 * Fecha: 17-02-2025
*/

//Variables globales
float calif, suma, promedio;

//Declaración de procedimientos y funciones
bool validaCalif(){
  while (calif < 0 || calif > 10) {
    printf("\n La calificación digita es erronea");
    printf("\n Solo se aceptan valores entre 0 y 10");
    printf("\n Digita nuevamente la calificación: ");
    scanf("%f", &calif);
  }
  return true;
}

void pedirCalif() {
  //Variables locales
  bool valido;
  int CuentaCalif;
  suma=0;
  for (CuentaCalif = 1; CuentaCalif <= 3; CuentaCalif++) {
    printf("\nDigita la calificaión %i del alumno: ", CuentaCalif);
    scanf("%f", &calif);
    valido = validaCalif();
    if (valido = true) {
      suma += calif;
    }
  }
}

float calcularProm() {
  return suma / 3;
}

void mostrarRes() {
  printf("\nEl promedio del alumno es: %.2f\n", promedio);
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  char resp;
  do {
    system("clear");
    pedirCalif();
    promedio = calcularProm();
    mostrarRes();
    printf("¿Deseas calcular otro promedio?\n");
    fflush(stdin);
    scanf(" %c", &resp);
  } while (resp == 's' || resp == 'S');
  return EXIT_SUCCESS;
}
