
#include "locale.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * Programa que calcula el promedio de 4 calificaciones de un alumno
 * y muestra su evaluación final
 * Autor : Ordaz Magos Juan Pablo
 * Fecha de creación: 2025-03-06
 * Versión: 1.0
 */
int cuenta;

float obtener_calificacion() {
  float calificacion;
  do {
    printf("Ingrese la calificación %i -> ", cuenta);
    scanf("%f", &calificacion);
    if (calificacion < 0 || calificacion > 10) {
      printf("Calificación no válida. Intente nuevamente.\n");
    }
  } while (calificacion < 0 || calificacion > 10);
  cuenta++;
  return calificacion;
}

float calcular_promedio() {
  float calif1, calif2, calif3, calif4;
  calif1 = obtener_calificacion();
  calif2 = obtener_calificacion();
  calif3 = obtener_calificacion();
  calif4 = obtener_calificacion();
  return (calif1 + calif2 + calif3 + calif4) / 4;
}

void obtener_leyenda(float promedio) {
  printf("\nNota para el alumno\n");
  if (round(promedio * 10) / 10 <= 6.9) {
    printf("Reprobado debes esforzarte más\n");
  } else if (round(promedio * 10) / 10 <= 7.9) {
    printf("Regular, aún puedes mejorar.\n");
  } else if (round(promedio * 10) / 10 <= 8.9) {
    printf("Buen trabajo\n");
  } else if (round(promedio * 10) / 10 <= 9.9) {
    printf("Felicitaciones, muy buen trabajo\n");
  } else {
    printf("Excelente Felicitaciones");
  }
}

int main() {
  char continuar;
  float promedio;
  setlocale(LC_ALL, "");
  do {
    cuenta = 1;
    system("clear");
    printf("Este programa calcula el promedio de 4 calificaciones de un alumno "
           "\n");
    promedio = calcular_promedio();
    printf("El promedio es %.2f\n", promedio);
    obtener_leyenda(promedio);
    printf("\n ¿Desea ingresar otro alumno? (s/n):  ");
    fflush(stdin);
    scanf(" %c", &continuar);
  } while (continuar == 's' || continuar == 'S');
  return 0;
}
