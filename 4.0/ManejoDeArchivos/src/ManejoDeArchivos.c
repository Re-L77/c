#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * Autor : Ordaz Magos Juan Pablo
 * Fecha de creación: mié 26 mar 2025 08:59:18 CST
 * Versión: 1.1
 *
 * Tipos de acceso a un archivo en C
 * r - Abre un archivo para lectura. Falla si el archivo no existe.
 * w - Abre un archivo para escritura. Si el archivo existe, lo sobrescribe; si
 * no existe, lo crea. a - Abre un archivo para adición. Si no existe, lo crea.
 * r+ - Abre un archivo para lectura y escritura. Si el archivo no existe,
 * falla. w+ - Abre un archivo para lectura y escritura. Si el archivo existe,
 * lo sobrescribe; si no existe, lo crea. a+ - Abre un archivo para lectura y
 * adición. Si no existe, lo crea.
 */

FILE *archivo;

void CrearArchivo() {
  archivo = fopen("ArchivoEjemplo.txt", "w");
  if (archivo != NULL) {
    printf("\nArchivo creado con éxito");
    printf(
        "\nteclea la información a guardar, para terminar presiona enter: \n");
    int p1;
    while ((p1 = getchar()) != '\n')
      ;                              // Limpiar el búfer de entrada
    while ((p1 = getchar()) != '\n') // Leer la entrada correctamente
      fputc(p1, archivo);
    fclose(archivo);
    printf("\nEl Archivo se ha cerrado");
  } else
    printf("\nNo se puede abrir el archivo");
}

void VerArchivo() {
  if ((archivo = fopen("ArchivoEjemplo.txt", "r")) != NULL) {
    printf("\nEl archivo existe, el contenido es el siguiente: \n");
    int p1;
    while ((p1 = fgetc(archivo)) != EOF) {
      putchar(p1);
    }
    fclose(archivo);
    printf("\nEl Archivo se ha cerrado");
  } else
    printf("\nNo se puede abrir el archivo");
}

int menu() {
  int opcion;
  printf("\n MENÚ\n");
  printf("\n1.- CrearArchivo");
  printf("\n2.- AbirArchivo");
  printf("\n3.- Salir");
  printf("\n¿Qué opción eliges?");
  scanf("%i", &opcion);
  while (getchar() != '\n')
    ; // Limpiar el búfer de entrada
  return opcion;
}

int main(int argc, char *argv[]) {
  int respuesta;
  setlocale(LC_ALL, "");
  do {
    // system("clear");
    respuesta = menu();
    switch (respuesta) {
    case 1:
      CrearArchivo();
      break;
    case 2:
      VerArchivo();
      break;
    case 3:
      break;
      printf("Saliendo del programa");
    default:
      printf("Elige un valor válido [1-3].");
      break;
    }

  } while (respuesta != 3);
  return EXIT_SUCCESS;
}
