#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

/*
* Este programa ejemplifica uso de ciclos anidados
* Autor: Ordaz Magos Juan Pablo
* Fecha de creaciÃ³n: 10/02/25
*/

int contadorCalif, resp;
float suma, calif, promedio;
//char resp;
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  printf("Este programa promedia 3 calificaciones de los alumnos qur desees...\n");
  do {
    suma = 0;
    for (int contadorCalif = 1; contadorCalif <= 3; contadorCalif++) {
      do {
        printf("Digita la calificaciÃ³n %i de alumno: ", contadorCalif);
        scanf("%f", &calif);
        if ((calif < 0) || (calif > 10)) {
          printf("El valor es incorrecto, ya que solo de aceptan valores entre [0-10].\n");
        }
      } while ((calif < 0) || (calif > 10));
      suma += calif;
    }
    promedio = suma / 3;
    printf("El promedio del alumno es : %.2f\n", promedio);
    printf("Â¿Deseas calcular el promedio de otro alumno? (0-No  1-SÃ­)\n");
    scanf("%i", &resp);
  } while (resp != 0);
  return EXIT_SUCCESS;
}