#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	Programa que ordena 3 n�meros enteros diferentes y verifica en caso de ser
	iguales.
	Autor: Ordaz Magos Juan Pablo
	Fecha de creaci�n: 20/01/25
*/
int primerNumero, segundoNumero, tercerNumero;
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	printf("Introduce el primer n�mero: ");
	scanf("%d", &primerNumero);
	printf("Introduce el segundo n�mero: ");
	scanf("%d", &segundoNumero);
	printf("Introduce el tercer n�mero: ");
	scanf("%d", &tercerNumero);

	// Validaci�n en caso de los n�meros sean iguales.
	if (primerNumero == segundoNumero && segundoNumero == tercerNumero)
	{
		printf("Los 3 n�meros son iguales.\n");
	}
	else if (primerNumero == segundoNumero)
	{
		if (primerNumero > tercerNumero)
		{
			printf("El primer y segundo n�mero son iguales y mayores que el tercer n�mero\n");
			printf("%d, %d > %d\n", primerNumero, segundoNumero, tercerNumero);
		}
		else
		{
			printf("El tercer n�mero es mayor que el primer y segundo n�mero\n");
			printf("%d > %d, %d\n", tercerNumero, primerNumero, segundoNumero);
		}
	}
	else if (segundoNumero == tercerNumero)
	{
		if (segundoNumero > primerNumero)
		{
			printf("El segundo y tercer n�mero son iguales y mayores que el primer n�mero\n");
			printf("%d < %d, %d\n", primerNumero, tercerNumero, segundoNumero);
		}
		else
		{
			printf("El primer n�mero es mayor que el segundo y tercer n�mero\n");
			printf("%d > %d, %d\n", primerNumero, segundoNumero, tercerNumero);
		}
	}
	else if (primerNumero == tercerNumero)
	{
		if (primerNumero > segundoNumero)
		{
			printf("El primer y tercer n�mero son iguales y mayores que el segundo n�mero.\n");
			printf("%d > %d < %d\n", primerNumero, segundoNumero, tercerNumero);
		}
		else
		{
			printf("El segundo n�mero es mayor que el primer y tercer n�mero.\n");
			printf("%d < %d > %d\n", primerNumero, segundoNumero, tercerNumero);
		}
	}
	// Una vez verificado que los n�meros son diferentes, se procede a ordenarlos.
	else if (primerNumero > segundoNumero && primerNumero > tercerNumero)
	{
		printf("El primer n�mero es el mayor.\n");
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
			printf("El segundo n�mero es el mayor.\n");
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
			printf("El tercer n�mero es el mayor.\n");
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
