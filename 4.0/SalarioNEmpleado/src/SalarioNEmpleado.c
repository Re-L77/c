#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#endif

/*
 * Programa que calcula el salario de N empleados con uso de archivos de texto
 * Autor : Ordaz Magos Juan Pablo
 * Fecha de creación: lun 31 mar 2025 07:15:37 CST
 * Versión: 1.1
 */

#define ARCHIVO "empleados.txt"

FILE *archivo;
int opcion, n;
typedef struct {
  int id;
  char departamento[100];
  float salario;
  float ventas;
} Empleado;

int opcionMenu() {
  printf("\n\t\tMenú\n");
  printf("1. Cargar datos.\n");
  printf("2. Ver datos\n");
  printf("3. Salir\n");
  printf("Selecciona una opcion: ");
  scanf("%d", &opcion);
  printf("\n");
  return opcion;
}

void limpiarPantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
void pedirN() {
  do {
    printf("\nNúmero de empleados: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("\n[ERROR] - Número inválido.");
    }
  } while (n <= 0);
}

int validarID() {
  int id;
  do {
    printf("\nIngrese ID del empleado: ");
    scanf("%d", &id);
    if (id <= 0) {
      printf("\n[ERROR] - Ingresa un ID válido.");
    }
  } while (id <= 0);
  return id;
}

float validarSalario() {
  float salario;
  do {
    printf("\nIngrese salario del empleado: ");
    scanf("%f", &salario);
    if (salario <= 0) {
      printf("\n[ERROR] - Ingresa un salario válido. (salario > 0)");
    }
  } while (salario <= 0);
  return salario;
}

float validarVentas() {
  float ventas;
  do {
    printf("\nIngrese ventas del empleado: ");
    scanf("%f", &ventas);
    if (ventas <= 0) {
      printf("\n[ERROR] - Ingresa una venta válida. (venta > 0)");
    }
  } while (ventas <= 0);
  return ventas;
}

void cargarDatos() {
  char departamento[100];
  archivo = fopen(ARCHIVO, "r+");
  if (archivo == NULL) {
    printf("\n[ERROR] - al abrir el archivo");
    return;
  }

  Empleado nuevoEmpleado;
  nuevoEmpleado.id = validarID();
  printf("\nIngresa el departamento: ");
  scanf(" %s", &departamento[0]);
  strcpy(nuevoEmpleado.departamento, departamento);
  nuevoEmpleado.salario = validarSalario();
  nuevoEmpleado.ventas = validarVentas();

  /*printf("\nid: %d, dep: %s, sal: %.2f, vent: %.2f", nuevoEmpleado.id,
         nuevoEmpleado.departamento, nuevoEmpleado.salario,
         nuevoEmpleado.ventas);*/
  fprintf(archivo, "%d|%s|%f|%f\n", nuevoEmpleado.id,
          nuevoEmpleado.departamento, nuevoEmpleado.salario,
          nuevoEmpleado.ventas);
  printf("\n------[OK] - Agregado.------");
  fclose(archivo);
}

void verDatos() {
  archivo = fopen(ARCHIVO, "r");
  if (archivo == NULL) {
    printf("\n[ERROR] - al abrir el archivo");
    return;
  }
  fclose(archivo);
}

void incrementar() {}
int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  do {
    limpiarPantalla();

    opcion = opcionMenu();
    switch (opcion) {
    case 1:
      pedirN();
      cargarDatos();
      break;
    case 2:
      verDatos();
      break;
    case 3:
      printf("\nSaliendo del programa...");
      break;
    default:
      printf("[ERROR] - Valor no admitido");
      break;
    }
  } while (opcion != 3);
  return EXIT_SUCCESS;
}
