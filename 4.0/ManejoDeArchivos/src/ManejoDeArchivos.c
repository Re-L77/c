#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

FILE *archivo;
char p1;

void CrearArchivo() {
  archivo = fopen("ArchivoEjemplo.txt", "w");
  if (archivo != NULL) {
    printf("\n Archivo creado con éxito \n");
    printf(
        "\n Teclea la información a guardar, para terminar presiona enter: \n");
    fflush(stdin);
    while ((p1 = getchar()) != '\n')
      fputc(p1, archivo);
    fclose(archivo);
    printf("\n El archivo se ha cerrado\n");
  } else
    printf("\n No se puede abrir el archivo\n");
}

void VerArchivo() {
  if ((archivo = fopen("ArchivoEjemplo.txt", "r")) != NULL) {
    printf("\n El archivo existe. El contenido es el siguiente: \n");
    while ((p1 = fgetc(archivo)) != EOF) // EOF indica el final del archivo
      putchar(p1);
    fclose(archivo);
    printf("\n Archivo cerrado\n");
  } else
    printf("\n No se pudo abrir el archivo\n");
}

int menu() {
  int opcion;
  printf("\n MENU\n");
  printf(" 1.- CREAR ARCHIVO\n");
  printf(" 2.- VER ARCHIVO\n");
  printf(" 3.- SALIR \n");
  printf("Â¿QUÃ‰ OPCIÃ“N ELIGES?: ");
  scanf("%d", &opcion);
  getchar(); // Limpia el buffer de entrada para evitar problemas con getchar()
  return opcion;
}

int main(int argc, char *argv[]) {
  int respuesta;
  setlocale(LC_ALL, "");
  do {
    system("clear"); // Cambiado para Linux
    respuesta = menu();
    switch (respuesta) {
    case 1:
      CrearArchivo();
      getchar(); // Para hacer una pausa antes de continuar
      break;
    case 2:
      VerArchivo();
      getchar();
      break;
    case 3:
      printf("\n Programa Terminado \n");
      break;
    default:
      printf("\n La opción elegida es inválida\n");
      getchar();
      break;
    }
  } while (respuesta != 3);

  return 0;
}
