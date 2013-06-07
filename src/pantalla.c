/*
 * pantalla.c
 *
 *  Created on: Jun 2, 2013
 *      Author: alfredo
 */

#include "pantalla.h"
#include "transferencia.h"
#include "string.h"

void pantalla()
{
	int opcion;
	do {
		printMenu();
		scanf("%d",&opcion);
		switch (opcion)
		{
			case 1:
				opcionSuma();
				break;
			case 2:
				opcionResta();
				break;
			case 3:
				opcionMultiplicacion();
				break;
			case 4:
				opcionDivision();
				break;
			case 8:
				opcionTransferencia();
				break;
		}
	} while (opcion != 9);
}

void printMenu(){
	printf("WesselSoft:\n\n");
	printf("Ingrese una Opcion:\n");
	printf("1-Suma de Complejos\n");
	printf("2-Resta de Complejos\n");
	printf("3-Multiplicacion de Complejos\n");
	printf("4-Division de Complejos\n");
	printf("5-Potencia de Complejos\n");
	printf("6-Radicacion de Complejos\n");
	printf("7-Suma de Fasores\n");
	printf("8-Funcion de Transferencia\n");
	printf("9-Salir\n\n");
}

void opcionSuma()
{
	//system("clear");
	tComplejo z1 = capturaComplejo();
	tComplejo z2 = capturaComplejo();
	tComplejo *resultado = sumar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionResta()
{
	//system("clear");
	tComplejo z1 = capturaComplejo();
	tComplejo z2 = capturaComplejo();
	tComplejo *resultado = restar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionMultiplicacion()
{
	//system("clear");
	tComplejo z1 = capturaComplejo();
	tComplejo z2 = capturaComplejo();
	tComplejo *resultado = multiplicar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionDivision()
{
	//system("clear");
	tComplejo z1 = capturaComplejo();
	tComplejo z2 = capturaComplejo();
	tComplejo *resultado = dividir(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionTransferencia()
{
	t_list *ceros, *polos;
	tComplejo punto;
	tComplejo complejoAux;
	double k;
	int i;

	ceros = list_create();
	polos = list_create();

	printf("\n Si desea ingresar Ceros de la Función, ingrese '1', sino '0'");
	scanf("%d",&i);

	while (i==1)
	{
		complejoAux = capturaComplejo();
		list_add(ceros, &complejoAux);
		printf("\nSi desea ingresar otro Cero de la Función, ingrese '1', sino '0'");
		scanf("%d",&i);
	}

	printf("\n Ingrese un Polo de la Función:");
	do {
		complejoAux = capturaComplejo();
		list_add(polos,&complejoAux);
		printf("Si desea ingresar otro Polo de la Función, ingrese '1', sino '0'");
		scanf("%d",&i);
	} while (i==1);

	printf("\n Ingrese la Constante de la Función (Nro Real):");
	scanf("%lf",&k);

	printf("Ingrese el Punto en el que desea evaluar la Función:");
	punto = capturaComplejo();

	printf("\n El resultado de la función es:");
	complejoAux = transferencia(ceros, polos, k, punto);

	printResultadoComplejo(&complejoAux);
}

tComplejo capturaComplejo()
{
	tComplejo z;
	int formaDeCaptura;
	printf("Ingrese un numero complejo:\n");
	printf("1-En forma binomica\n");
	printf("2-En forma polar\n\n");
	scanf("%d",&formaDeCaptura);
	switch(formaDeCaptura)
	{
		case 1:
			z = capturaFormaBinomica();
			break;
		case 2:
			z = capturaFormaPolar();
			break;
	}
	return z;
}

tComplejo capturaFormaBinomica()
{
	tComplejo z;
	char *complejo=NULL, *token=NULL;

	printf("Ingrese un complejo de la forma (a,b): ");

	if ((complejo=(char *)calloc(1, sizeof(char)+sizeof(int)+sizeof(char)+sizeof(int)+sizeof(char))) == NULL) {
		perror("\nError al reservar memoria para el complejo binomico.");
	}

	scanf("%s",complejo);

	token=strtok(complejo, "(,)");
	z.stBinomica.dReal=atof(token);
	token=strtok(NULL, "(,)");
	z.stBinomica.dImaginaria=atof(token);

	free(complejo);

	return z;
}

tComplejo capturaFormaPolar()
{
	tComplejo z;
	char *complejo, *token;
	printf("Ingrese un complejo de la forma [a;b]: ");

	if ((complejo=(char *)calloc(1, sizeof(char)+sizeof(int)+sizeof(char)+sizeof(int)+sizeof(char))) == NULL) {
		perror("\nError al reservar memoria para el complejo polar.");
	}

	scanf("%s",complejo);

	token=strtok(complejo, "[;]");
	z.stPolar.dModulo=atof(token);
	token=strtok(NULL, "[;]");
	z.stPolar.dArgumento=atof(token);

	free(complejo);

	return z;
}

void printResultadoComplejo(tComplejo *z)
{
	printf("El resultado es:\n");
	if (esPolar(z))
	{
		printResultadoBinomica(pasarABinomica(z));
		printResultadoPolar(z);
	} else {
		printResultadoBinomica(z);
		printResultadoPolar(pasarAPolar(z));
	}
	//printf("Presione una tecla para continuar");
	//system("pause");
}

void printResultadoPolar(tComplejo *z)
{
	printf("En forma polar: [%.2lf;%.2lf]\n",z->stPolar.dModulo,z->stPolar.dArgumento);
}

void printResultadoBinomica(tComplejo *z)
{
	printf("En forma binomica: (%.2lf,%.2lf)\n",z->stBinomica.dReal,z->stBinomica.dImaginaria);
}
