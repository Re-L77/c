#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
typedef struct
{
  int id;
  char departamento[100];
  float salario;
  float ventas;
} Empleado;

int opcionMenu()
{
  printf("\n\n\t\tMenú\n");
  printf("1. Cargar datos.\n");
  printf("2. Ver datos\n");
  printf("3. Salir\n");
  printf("Selecciona una opcion: ");
  scanf("%d", &opcion);
  printf("\n");
  return opcion;
}

void limpiarPantalla()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
void pedirN()
{
  do
  {
    printf("\nNúmero de empleados: ");
    scanf("%d", &n);
    if (n <= 0)
    {
      printf("\n[ERROR] - Número inválido.");
    }
  } while (n <= 0);
}

int validarID()
{
  int id;
  do
  {
    printf("\nIngrese ID del empleado: ");
    scanf("%d", &id);
    if (id <= 0)
    {
      printf("\n[ERROR] - Ingresa un ID válido.");
    }
  } while (id <= 0);
  return id;
}

float validarSalario()
{
  float salario;
  do
  {
    printf("\nIngrese salario del empleado: ");
    scanf("%f", &salario);
    if (salario <= 0)
    {
      printf("\n[ERROR] - Ingresa un salario válido. (salario > 0)");
    }
  } while (salario <= 0);
  return salario;
}

float validarVentas()
{
  float ventas;
  do
  {
    printf("\nIngrese ventas del empleado: ");
    scanf("%f", &ventas);
    if (ventas <= 0)
    {
      printf("\n[ERROR] - Ingresa una venta válida. (venta > 0)");
    }
  } while (ventas <= 0);
  return ventas;
}

void cargarDatos()
{
  archivo = fopen(ARCHIVO, "w+");
  if (archivo == NULL)
  {
    printf("\n[ERROR] - al abrir el archivo");
    return;
  }
  int i;
  for (i = 1; i <= n; i++)
  {
    limpiarPantalla();
    printf("\n\tEmpleado %d\n", i);
    printf("--------------------------------\n");
    Empleado nuevoEmpleado;
    nuevoEmpleado.id = validarID();
    printf("\nIngresa el departamento: ");
    scanf(" %99s", nuevoEmpleado.departamento);
    nuevoEmpleado.salario = validarSalario();
    nuevoEmpleado.ventas = validarVentas();
    fprintf(archivo, "%d,%s,%.2f,%.2f\n", nuevoEmpleado.id,
            nuevoEmpleado.departamento, nuevoEmpleado.salario,
            nuevoEmpleado.ventas);
  }
  printf("\n------[OK] - Agregados.------");
  fclose(archivo);
}

void verDatos()
{
  archivo = fopen(ARCHIVO, "r");
  if (archivo == NULL)
  {
    printf("\n[ERROR] - al abrir el archivo");
    return;
  }
  printf("\n\t\tDatos de empleados\n");
  printf("ID|Departamento|Salario|Ventas\n");
  printf("--------------------------------\n");
  Empleado empleado;
  while (fscanf(archivo, "%d,%99[^,],%f,%f\n", &empleado.id,
                empleado.departamento, &empleado.salario,
                &empleado.ventas) != EOF)
  {
    printf("%d,%s,%.2f,%.2f\n", empleado.id, empleado.departamento,
           empleado.salario, empleado.ventas);
  }
  printf("--------------------------------\n");
  fclose(archivo);
}

void incrementar()
{
  archivo = fopen(ARCHIVO, "r");
  if (archivo == NULL)
  {
    printf("\n[ERROR] - al abrir el archivo");
    return;
  }
  FILE *temp = fopen("temp.txt", "w");
  if (temp == NULL)
  {
    printf("\n[ERROR] - al crear archivo temporal");
    fclose(archivo);
    return;
  }
  Empleado empleado;
  while (fscanf(archivo, "%d,%99[^,],%f,%f\n", &empleado.id,
                empleado.departamento, &empleado.salario,
                &empleado.ventas) != EOF)
  {
    if (empleado.ventas > 500000.00)
    {
      empleado.salario *= 1.1;
    }
    fprintf(temp, "%d,%s,%.2f,%.2f\n", empleado.id,
            empleado.departamento, empleado.salario,
            empleado.ventas);
  }
  fclose(archivo);
  fclose(temp);
  remove(ARCHIVO);
  rename("temp.txt", ARCHIVO);
  printf("\n------[OK] - Salarios actualizados.------\n");
}

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  do
  {
    opcion = opcionMenu();
    switch (opcion)
    {
    case 1:
      limpiarPantalla();
      pedirN();
      cargarDatos();
      incrementar();
      break;
    case 2:
      limpiarPantalla();
      verDatos();
      break;
    case 3:
      limpiarPantalla();
      printf("\nSaliendo del programa...\n");
      break;
    default:
      limpiarPantalla();
      printf("[ERROR] - Valor no admitido\n");
      break;
    }
  } while (opcion != 3);
  return EXIT_SUCCESS;
}