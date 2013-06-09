/*
============================================================================
 Name        : pantalla.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Funciones de la interfaz de usuario.
 Version     :
 ============================================================================
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
				opcionDivision();
				break;
			case 5:
				opcionPotencia();
				break;
			case 6:
				opcionRadicacion();
				break;
			case 7:
				opcionRaicesPrimitivas();
				break;
			case 8:
				opcionSumaFasores();
				break;
			case 9:
				opcionTransferencia();
				break;
		}
	} while (opcion != 10);
}

void printMenu(){
	printf("WesselSoft:\n\n");
	printf("Ingrese una Opcion:\n");
	printf(" 1-Suma de Complejos\n");
	printf(" 2-Resta de Complejos\n");
	printf(" 3-Multiplicacion de Complejos\n");
	printf(" 4-Division de Complejos\n");
	printf(" 5-Potencia de Complejos\n");
	printf(" 6-Radicacion de Complejos\n");
	printf(" 7-Raices primitivas\n");
	printf(" 8-Suma de Fasores\n");
	printf(" 9-Funcion de Transferencia\n");
	printf("10-Salir\n\n");
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

void opcionPotencia()
{
	//system("clear");
	tComplejo z = capturaComplejo();
	int n = capturaEntero();
	t_list *resultado = potenciar(&z,n);
	tComplejo *complejo = (tComplejo *) resultado->head->data;
	printResultadoComplejo(complejo);
}
void opcionRadicacion()
{
	//system("clear");
	tComplejo z = capturaComplejo();
	int n = capturaEntero();
	t_list *resultado = radicacion(&z,n);
	printResultadoListaComplejos(resultado);
}

void opcionRaicesPrimitivas()
{
	//system("clear");
	tComplejo z = capturaComplejo();
	int n = capturaEntero();
	t_list *resultado = raicesPrimitivas(&z,n);
	printResultadoListaComplejos(resultado);
}

void opcionSumaFasores()
{
	tFasor *resultado;
	tFasor fasor1 = capturaFasor();
	tFasor fasor2 = capturaFasor();
	if (fasor1.dFrecuencia == fasor2.dFrecuencia)
	{
		fasor2 = validarFasor(fasor2,fasor1.iFuncion);
		resultado = sumaFasores(fasor1,fasor2);
		printResultadoFasor(resultado);
	} else {
		printf("Debe ingresar fasores con igual frecuencia\n");
	}
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
int capturaEntero()
{
	int a;
	printf("Ingrese un numero entero:\n");
	scanf("%d",&a);
	return a;
}
tFasor capturaFasor()
{
	tFasor fasor;
	fasor.iFuncion = capturaFasorFuncion();
	fasor.dAmplitud = capturaFasorAmplitud();
	fasor.dFrecuencia = capturaFasorFrecuencia();
	fasor.dFase = capturaFasorFase();
	return fasor;
}
int capturaFasorFuncion()
{
	int funcion;
	printf("Elija la funcion:\n");
	printf("1-Coseno:\n");
	printf("2-Seno:\n");
	scanf("%d",&funcion);
	return funcion;
}
double capturaFasorAmplitud()
{
	double amplitud;
	printf("Ingresa la Amplitud:\n");
	scanf("%lf",&amplitud);
	return amplitud;
}
double capturaFasorFrecuencia()
{
	double frecuencia;
	printf("Elija la Frecuencia:\n");
	scanf("%lf",&frecuencia);
	return frecuencia;
}
double capturaFasorFase()
{
	double fase;
	printf("Elija la Fase:\n");
	scanf("%lf",&fase);
	return fase;
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
void printResultadoListaComplejos(t_list *resultado)
{
	list_iterate(resultado, imprimirRaices);
	list_destroy(resultado);
}
void printResultadoFasor(tFasor *resultado)
{
	char *funcion;
	if (resultado->iFuncion == 1)
	{
		funcion = "cos";
	} else {
		funcion = "sen";
	}
	printf("(f+g)(t) = %.2lf %s(%.2lft + %.2lf)\n\n",resultado->dAmplitud, funcion, resultado->dFrecuencia, resultado->dFase);
}
void imprimirRaices(void *unComplejo)
{
	tComplejo *raiz;
	raiz = (tComplejo *) unComplejo;
	printf("[%.4f, %.4f]\n", raiz->stPolar.dModulo, raiz->stPolar.dArgumento);
}
tFasor validarFasor(tFasor fasor, int funcion)
{
	if (fasor.iFuncion == funcion) {
		return fasor;
	} else {
		tFasor fasorEquivalente = fasor;
		double defaseje = 3.1416 / 2;
		if (funcion == 1) {
			fasorEquivalente.dFase = fasor.dFase + defaseje;
		} else {
			fasorEquivalente.dFase = fasor.dFase - defaseje;
		}
		fasorEquivalente.iFuncion = funcion;
		return fasorEquivalente;
	}

}
