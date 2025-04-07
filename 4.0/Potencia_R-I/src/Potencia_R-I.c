#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Programa que ejemplifica el uso de funciones recursivas e iterativas
 * para calcular potencias.
 * Autor : Ordaz Magos Juan Pablo
 * Fecha de creación: lun 30 mar 2025
 * Versión: 1.1
 */

int base, exponente, resultado;

int menu()
{
  int opcion;
  printf("\nMenú\n");
  printf("\n1.- Potencia usando función iterativa.");
  printf("\n2.- Potencia usando función recursiva.");
  printf("\n3.- Salir");
  printf("\n\n¿Qué opción eliges? ");
  scanf("%i", &opcion);
  return opcion;
}

bool PedirBaseYExponente()
{
  do
  {
    printf("\nDigita la base (debe ser positiva): ");
    scanf("%i", &base);
    if (base < 0)
    {
      printf("\nLa base no puede ser negativa. Intenta nuevamente.");
    }
  } while (base < 0);

  printf("Digita el exponente: ");
  scanf("%i", &exponente);
  return true;
}

void MostrarResultado(const char *info)
{

  printf("\nEl resultado de la potencia usando %s es %i", info, resultado);
  getchar(); // Leer un solo carácter
}

void PotenciaIterativa()
{
  bool verifica = PedirBaseYExponente();
  if (verifica)
  {
    resultado = 1;
    for (int i = 0; i < exponente; i++)
    {
      resultado *= base;
    }
    MostrarResultado("iteración");
  }
}

int PotenciaRecursiva(int base, int exponente)
{
  if (exponente == 0)
    return 1;
  else
    return base * PotenciaRecursiva(base, exponente - 1);
}

int main(int argc, char *argv[])
{
  int respuesta;
  bool verifica;
  setlocale(LC_ALL, "");
  do
  {
    // system("clear");
    respuesta = menu();
    switch (respuesta)
    {
    case 1:
      PotenciaIterativa();
      break;
    case 2:
      verifica = PedirBaseYExponente();
      if (verifica)
      {
        resultado = PotenciaRecursiva(base, exponente);
        MostrarResultado("recursión");
      }
      break;
    case 3:
      printf("\nSaliendo del programa.");
      break;
    default:
      printf("\nLa opción que eligiste no es válida.");
      printf("\nElige un número entre 1 y 3...");
    }
  } while (respuesta != 3);
  return EXIT_SUCCESS;
}
