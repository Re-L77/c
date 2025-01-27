#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
 * Este programa calcula el �rea de un tri�ngulo
 * validando las entradas.
 * Autor: Ordaz Magos Juan Pablo
 * Fecha de creaci�n: 20/01/25
 */

float baseTriangulo, alturaTriangulo, area;
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  do
  {
    printf("Escribe el valor de la base del tri�ngulo : ");
    scanf("%f", &baseTriangulo);
    printf("\nEscribe el valor de la altura del tri�ngulo: ");
    scanf("%f", &alturaTriangulo);

    if ((baseTriangulo <= 0) || (alturaTriangulo <= 0))
    {
      printf("\nLos valores admitidos deben ser valores mayores a 0.\n");
    }
  } while ((baseTriangulo <= 0) || (alturaTriangulo <= 0));

  area = baseTriangulo * alturaTriangulo / 2;
  printf("\n�rea del tri�ngulo: %.2f\n", area);

  return EXIT_SUCCESS;
}