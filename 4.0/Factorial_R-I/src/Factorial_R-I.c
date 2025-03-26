
#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Programa que ejemplifica el uso de funciones recursivas, iterativas
 * funciones y porcedimientos con y sin argumentos, con variables locales y
 * globales. Autor : Ordaz Magos Juan Pablo Fecha de creación: lun 24 mar 2025
 * 08:27:26 CST Versión: 1.1
 */

int num, factorial;

int menu() {
  int opcion;
  printf("\nMenú\n");
  printf("\n1.- Factorial usando función iterativa.");
  printf("\n2.- Factorial usando función recursiva.");
  printf("\n3.- Salir");
  printf("\n\n¿Qué opción eliges?");
  scanf("%i", &opcion);
  return opcion;
}

bool PedirNumero() {
  printf("\nDigita el número del factorial a calcular: ");
  scanf("%i", &num);
  while (num <= 0) {
    printf("\nNo se puede calcular el factorial de un número negativo.");
    printf("\nIntenta nuevamente: ");
    scanf("%i", &num);
  }
  return true;
}

void MostrarResultado(const char *info) {
  initscr(); // Iniciar modo ncurses
  noecho();  // No mostrar caracteres en pantalla
  cbreak();  // Desactivar el buffer de línea (no se necesita Enter)
  printw("\nEl factorial usando %s es %i", info, factorial);
  refresh();
  char c = getch(); // Leer un solo carácter
  endwin();         // Salir de ncurses
}

void FactorialIterativo() {
  bool verifica;
  int contador;
  verifica = PedirNumero();
  if (verifica) {
    factorial = 1;
    for (contador = 1; contador <= num; contador++) {
      factorial = factorial * contador;
    }
    MostrarResultado("iteración");
  }
}

int FactorialRecursivo(int num) {
  if (num <= 1)
    return 1;
  else
    return (num * FactorialRecursivo(num - 1));
}

int main(int argc, char *argv[]) {
  int respuesta;
  bool verifica;
  setlocale(LC_ALL, "");
  do {
    system("clear");
    respuesta = menu();
    switch (respuesta) {
    case 1:
      FactorialIterativo();
      break;
    case 2:
      verifica = PedirNumero();
      if (verifica) {
        factorial = FactorialRecursivo(num);
        MostrarResultado("Recursión");
      }
      break;
    case 3:
      printf("\nSaliendo del programa.");
      break;
    default:
      printf("\nLa opción que eligiste no es valida.");
      printf("\nElige un número entre 1 y 3...");
    }
  } while (respuesta != 3);
  return EXIT_SUCCESS;
}
