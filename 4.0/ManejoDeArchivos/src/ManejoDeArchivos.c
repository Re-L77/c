#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Tipos de acceso de archivos de texto

  r archivo de solo lectura
  w archivo de solo escritura, si ya existe se sobrescribe
  a archivo para agregar datos al final, si no existe crea uno nuevo
  r+ archivo para realizar modificaciones, permite leer y escribir, el archivo tiene que existir
  w+ archivo para leer y escribir, si existe se sobrescribe
  a+ archivo para lectura y para agregar datos al final, si no existe se crea uno nuevo
  COMPLETAR INFORMACION
  Autor: Ordaz Magos Juan Pablo
  Fecha 26/03/25
 */
FILE *archivo; // Declaracion de la variable archivo tipo apuntador(Direccion en Hx) a un archivo
char p1;

void CrearArchivo()
{
  archivo = fopen("ArchivoEjemplo.txt", "w"); // Instruccion que asigna la direccion del archivo
  if (archivo != NULL)                        // Esta instruccion que sea una direccion valida
  {
    printf("\n Archivo creado con exito \n");
    printf("\n Teclea la informacion a guardar, para terminar presiona enter \n");
    fflush(stdin);
    while ((p1 = getchar()) != '\n') // ciclo que se repita hasta que lea el caracter ENTER
      fputc(p1, archivo);            // guarda la variable p1 en el archivo
    fclose(archivo);                 // Cierra correctamente la conexion al archivo
    printf("\n El archivo se ha cerrado");
  }
  else
    printf("\n No se puede abrir el archivo /n");
}

void VerArchivo()
{
  if ((archivo = fopen("ArchivoEjemplo.txt", "r")) != NULL)
  {
    printf("\n El archivo existe el contenido es el siguiente \n");
    while (!feof(archivo)) // ciclo que se repite mientras no sea el fin del archivo
    {
      p1 = fgetc(archivo);
      if (p1 != 'ÿ')
        putchar(p1);
    }
    fclose(archivo);
    printf("\n Archivo cerrado");
  }
  else
    printf("\n archivo cerrado\n");
}

int menu()
{
  int opcion;
  printf("\n MENU\n");
  printf("\n 1.- CREAR ARCHIVO\n");
  printf("\n 2.- VER ARCHIVO\n");
  printf("\n 3.- SALIR \n");
  printf("\nQUE OPCION ELIGES \n");
  scanf("%i", &opcion);
  return opcion;
}

int main(int argc, char *argv[])
{
  int respuesta;
  setlocale(LC_ALL, "");
  do
  {
    system("cls");
    respuesta = menu();
    switch (respuesta)
    {
    case 1:
      CrearArchivo();
      getch();
      break;
    case 2:
      VerArchivo();
      getch();
      break;
    case 3:
      printf("\n Programa Terminado \n");
      break;
    default:
      printf("\n La opciÃ³n elegida es invalida");
      getch();
      break;
    }
  } while (respuesta != 3);
  return 0;
}
