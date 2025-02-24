#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"
/*
* Programa que calcula el monto de n artículos.
* Autor: Ordaz Magos Juan Pablo
* Fecha: 24-02-25
* Versión: 1.0
*/

int articulos, contador;
float monto, precio;
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  char res;
  do {
    monto = 0;
    contador = 0;
    system("clear");
    do {
      printf("Ingresa la cantidad de artículos: ");
      scanf("%i",&articulos);
      if (articulos <= 0) {
        printf("Error debe ser mayor a 0.\n");
      }
    }while (articulos <= 0 );
    while (contador != articulos) {
      do {
        printf("Precio del artículo [%i]: ", contador);
        scanf("%f", &precio);
        if (precio <= 0) {
          printf("Error debe ser mayor a 0.\n");
        }
      }while (precio <= 0);
      monto += precio;
      contador++;
    }
    printf("\nMonto total %.2f\n", monto);
    printf("¿Desear calcular de otro monto? ");
    fflush(stdin);
    scanf(" %c", &res);
  }while (res == 's' || res == 'S');
   return EXIT_SUCCESS;
}
