#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
	Programa que calcula promedios de 3 calificaciones
	de N alumnos.
	Autor: Ordaz Magos Juan Pablo
	Fecha de creación: 26/01/25
*/
int alumnos, i, j;
float calificacion, sumaCalificaciones = 0, promedio;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	printf("Cantidad de alumnos a promediar: ");
	scanf("%d", &alumnos);
	if (alumnos <= 0) {
		printf("Solo se admiten valores mayores a 0.");
	} else {
		for(i = 1; i <= alumnos;i++){
			sumaCalificaciones=0;
			printf("Alumno [%d]: \n", i);
			for(j = 1; j <= 3; j++){
				calificacion=0;
				printf("Calificación %: ");
				scanf("%f", &calificacion);
				if(calificacion < 0 || calificacion > 10){
					printf("¡Error, no se admiten calificaciones menores a 0 y mayores a 10!");
					return 0;
				} else {
					sumaCalificaciones+=calificacion;
				}
			}
			promedio = sumaCalificaciones / 3;
			printf("Promedio del alumno [%d] : %.2f\n", i, promedio);
			printf("----------------------------------------------\n");
		}
	}
	return 0;
}
