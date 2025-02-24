#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"
/*
* Programa que calcula el monto de n artículos con uso de subrutinas.
* Autor: Ordaz Magos Juan Pablo
* Fecha: 24-02-25
* Versión: 2.0
*/

int articulos, contador;
float monto, precio;

void leerArticulos(){
  do {
    printf("Ingresa la cantidad de artículos: ");
    scanf("%i",&articulos);
    if (articulos <= 0) {
      printf("Error debe ser mayor a 0.\n");
    }
  }while (articulos <= 0 );
}

void leerPrecio(){
 do {
   printf("Precio del artículo: ");
   scanf("%f", &precio);
   if (precio <= 0) {
     printf("Error debe ser mayor a 0.\n");
   }
   }while (precio <= 0);
}

void calcularMonto(){
  contador = 0;
  monto = 0;
  while (contador != articulos) {
    leerPrecio();
    monto += precio;
    contador++;
  }
}

void mostrarMonto() {
  printf("Monto total: %.2f\n", monto);
}

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  char res;
  do {
    system("clear");
    leerArticulos();
    calcularMonto();
    mostrarMonto();
    printf("¿Desear calcular de otro monto? ");
    fflush(stdin);
    scanf(" %c", &res);
  }while (res == 's' || res == 'S');
   return EXIT_SUCCESS;
}
