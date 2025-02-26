#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"
/*
* Programa que calcula el monto de n artículos con uso de subrutinas y valores locales:.
* Autor: Ordaz Magos Juan Pablo
* Fecha: 25-02-25
* Versión: 3.0
*/

int leerArticulos();
float calcularMonto(float articulos);
void mostrarMonto(float monto);

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  float total;
  char res;
  do {
    system("clear");
    total = calcularMonto(leerArticulos());
    mostrarMonto(total);
    printf("\n¿Desear calcular de otro monto? ");
    fflush(stdin);
    scanf(" %c", &res);
  }while (res == 's' || res == 'S');
   return EXIT_SUCCESS;
}

int leerArticulos(){
  static int articulos;
  do {
    printf("Ingresa la cantidad de artículos: ");
    scanf("%i",&articulos);
    if (articulos <= 0) {
      printf("Error debe ser mayor a 0.\n");
    }
  }while (articulos <= 0 );
  return articulos;
}

float leerPrecio(){
  static float precio; 
  do {
    printf("Precio del artículo:");
    scanf("%f", &precio);
    if (precio <= 0) {
      printf("Error debe ser mayor a 0.\n");
    }
  }while (precio <= 0);
  return precio;
}

float calcularMonto(float articulos){
  static int contador;
  static float monto;
  monto = 0;
  contador = 0;
  while (contador != articulos) {
    monto += leerPrecio();
    contador++;
  }
  return monto;
}

void mostrarMonto(float monto) {
  printf("Monto total: %.2f\n", monto);
}
