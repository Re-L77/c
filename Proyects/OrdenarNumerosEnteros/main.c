#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	Programa que ordena 3 números enteros diferentes y verifica en caso de ser
	iguales.
	Autor: Ordaz Magos Juan Pablo
	Fecha de creación: 20/01/25
*/
int primerNumero, segundoNumero, tercerNumero;
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	printf("Introduce el primer número: ");
	scanf("%d", &primerNumero);
	printf("Introduce el segundo número: ");
	scanf("%d", &segundoNumero);
	printf("Introduce el tercer número: ");
	scanf("%d", &tercerNumero);

	// Validación en caso de los números sean iguales.
	if (primerNumero == segundoNumero && segundoNumero == tercerNumero)
	{
		printf("Los 3 números son iguales.\n");
	}
	else if (primerNumero == segundoNumero)
	{
		if (primerNumero > tercerNumero)
		{
			printf("El primer y segundo número son iguales y mayores que el tercer número.\n");
			printf("%d, %d > %d\n", primerNumero, segundoNumero, tercerNumero);
		}
		else
		{
			printf("El tercer número es mayor que el primer y segundo número.\n");
			printf("%d > %d, %d\n", tercerNumero, primerNumero, segundoNumero);
		}
	}
	else if (segundoNumero == tercerNumero)
	{
		if (segundoNumero > primerNumero)
		{
			printf("El segundo y tercer número son iguales y mayores que el primer número.\n");
			printf("%d < %d, %d\n", primerNumero, tercerNumero, segundoNumero);
		}
		else
		{
			printf("El primer número es mayor que el segundo y tercer número.\n");
			printf("%d > %d, %d\n", primerNumero, segundoNumero, tercerNumero);
		}
	}
	else if (primerNumero == tercerNumero)
	{
		if (primerNumero > segundoNumero)
		{
			printf("El primer y tercer número son iguales y mayores que el segundo número.\n");
			printf("%d > %d < %d\n", primerNumero, segundoNumero, tercerNumero);
		}
		else
		{
			printf("El segundo número es mayor que el primer y tercer número.\n");
			printf("%d < %d > %d\n", primerNumero, segundoNumero, tercerNumero);
		}
	}
	// Una vez verificado que los números son diferentes, se procede a ordenarlos.
	else if (primerNumero > segundoNumero && primerNumero > tercerNumero)
	{
		printf("El primer número es el mayor.\n");
		if (segundoNumero > tercerNumero)
		{
			printf("%d, %d, %d\n", primerNumero, segundoNumero, tercerNumero);
		}
		else
		{
			printf("%d > %d > %d\n", primerNumero, tercerNumero, segundoNumero);
		}
	}
	else
	{
		if (segundoNumero > primerNumero && segundoNumero > tercerNumero)
		{
			printf("El segundo número es el mayor.\n");
			if (primerNumero > tercerNumero)
			{
				printf("%d, %d, %d\n", segundoNumero, primerNumero, tercerNumero);
			}
			else
			{
				printf("%d > %d > %d\n", segundoNumero, tercerNumero, primerNumero);
			}
		}
		else
		{
			printf("El tercer número es el mayor.\n");
			if (primerNumero > segundoNumero)
			{
				printf("%d, %d, %d\n", tercerNumero, primerNumero, segundoNumero);
			}
			else
			{
				printf("%d > %d > %d\n", tercerNumero, segundoNumero, primerNumero);
			}
		}
	}
	return 0;
}
