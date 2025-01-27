#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
 * Este programa calcula el área de un triángulo
 * validando las entradas.
 * Autor: Ordaz Magos Juan Pablo
 * Fecha de creación: 20/01/25
 */

float baseTriangulo, alturaTriangulo, area;
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  do
  {
    printf("Escribe el valor de la base del triángulo : ");
    scanf("%f", &baseTriangulo);
    printf("\nEscribe el valor de la altura del triángulo: ");
    scanf("%f", &alturaTriangulo);

    if ((baseTriangulo <= 0) || (alturaTriangulo <= 0))
    {
      printf("\nLos valores admitidos deben ser valores mayores a 0.\n");
    }
  } while ((baseTriangulo <= 0) || (alturaTriangulo <= 0));

  area = baseTriangulo * alturaTriangulo / 2;
  printf("\nÁrea del triángulo: %.2f\n", area);

  return EXIT_SUCCESS;
}
