#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
	Programa que genera la tabla de multiplicar de un n�mero dado
	con un cliclo While.
	Autor: Ordaz Magos Juan Pablo
	Fecha de creaci�n: 26/01/25
*/
int numero, i = 1;
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	printf("Introduce un n�mero para generar su tabla de multiplicar: ");
	scanf("%d", &numero);

	while (i <= 10) {
		printf("%d x %d = %d\n", numero, i, numero * i);	
		i++;
	}
	return 0;
}
