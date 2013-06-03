/*
 * pantalla.c
 *
 *  Created on: Jun 2, 2013
 *      Author: alfredo
 */

#include "pantalla.h"

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
				opcionDivicion();
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
	printf("4-Divicion de Complejos\n");
	printf("5-Potencia de Complejos\n");
	printf("6-Radicacion de Complejos\n");
	printf("7-Suma de Fasores\n");
	printf("8-Funcion de Transferencia\n");
	printf("9-Salir\n");
}

void opcionSuma()
{
	//system("clear");
	tComplejo z1 = capturaComlejo();
	tComplejo z2 = capturaComlejo();
	tComplejo *resultado = sumar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionResta()
{
	//system("clear");
	tComplejo z1 = capturaComlejo();
	tComplejo z2 = capturaComlejo();
	tComplejo *resultado = restar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionMultiplicacion()
{
	//system("clear");
	tComplejo z1 = capturaComlejo();
	tComplejo z2 = capturaComlejo();
	tComplejo *resultado = multiplicar(&z1,&z2);
	printResultadoComplejo(resultado);
}

void opcionDivicion()
{
	//system("clear");
	tComplejo z1 = capturaComlejo();
	tComplejo z2 = capturaComlejo();
	tComplejo *resultado = dividir(&z1,&z2);
	printResultadoComplejo(resultado);
}

tComplejo capturaComlejo()
{
	tComplejo z;
	int formaDeCaptura;
	printf("Ingrese un numero complejo:\n");
	printf("1-En forma binomica\n");
	printf("2-En forma polar\n");
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
	char *complejo;
	printf("Ingrese un complejo de la forma (a,b): ");
	scanf("%s",complejo);
	/*
	Hay que hacer que capture varios valores:
	char* complejo;
	printf("Ingrese un complejo de la forma (a,b): ");
	scanf("%s",complejo);
	printf("%s",complejo);
	char valores[strlen(complejo)-1];
	strncpy(valores,complejo+1,strlen(complejo)-2);
	valores[strlen(complejo)-2] = '\0';
	printf("%s",valores);
	char *var1 = strtok(valores,",");
	printf("%s",var1);
	*/
	z.stBinomica.dReal = atof(&complejo[1]);
	z.stBinomica.dImaginaria = atof(&complejo[3]);
	return z;
}

tComplejo capturaFormaPolar()
{
	tComplejo z;
	char complejo[5];
	printf("Ingrese un complejo de la forma [a;b]: ");
	scanf("%s",complejo);
	z.stPolar.dModulo = atof(&complejo[1]);
	z.stPolar.dArgumento = atof(&complejo[3]);
	return z;
}

void printResultadoComplejo(tComplejo *z)
{
	printf("El resultado es:\n");
	if (esPolar(z))
	{
		printResultadorBinomica(pasarABinomica(z));
		printResultadorPolar(z);
	} else {
		printResultadorBinomica(z);
		printResultadorPolar(pasarAPolar(z));
	}
	//printf("Presione una tecla para continuar");
	//system("pause");
}

void printResultadorPolar(tComplejo *z)
{
	printf("En forma polar: [%.2lf;%.2lf]\n",z->stPolar.dModulo,z->stPolar.dArgumento);
}

void printResultadorBinomica(tComplejo *z)
{
	printf("En forma binomica: (%.2lf,%.2lf)\n",z->stBinomica.dReal,z->stBinomica.dImaginaria);
}
