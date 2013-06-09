/*
============================================================================
 Name        : funciones_complejos.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Funciones que realizan operaciones con complejos.
 Version     :
 ============================================================================
 */
#include "complejo.h"
#include <math.h>
#include <stdlib.h>
#include "list.h"


#define PI 3.141592654



double calcularModulo(tComplejo unComplejo) {
	double sumaDeCuadrados = pow(unComplejo.stBinomica.dReal, 2) +
			                  pow(unComplejo.stBinomica.dImaginaria, 2);

	return sqrt(sumaDeCuadrados);
}

/******************************************************************************/
/* Funcion: calcularArgumento                                                 */
/* Descripcion: devuelve el argumento de un complejo, en radianes.            */
/*              Si la componente real del complejo es 0 y la parte imaginaria */
/*              es positiva, devuelve PI; si la parte imaginaria es negativa, */
/*              devuelve 3/2*PI.                                              */
/* Precondiciones: las componentes del numero complejo no deben ser ambas 0.  */
/******************************************************************************/
double calcularArgumento(tComplejo unComplejo) {

	if (unComplejo.stBinomica.dReal == 0)
	    {
		if (unComplejo.stBinomica.dImaginaria < 0)
		    return 3 * PI / 2;
		else
			return PI;
	    }
	else
	    return atan2(unComplejo.stBinomica.dImaginaria, unComplejo.stBinomica.dReal);
}

/******************************************************************************/
/* Funcion: calcularParteReal                                                 */
/* Descripcion: dado un complejo en forma polar, calcula la parte real de la  */
/*               forma binomica.                                              */
/* Precondiciones:                                                            */
/******************************************************************************/
double calcularParteReal(tComplejo unComplejo) {
	return unComplejo.stPolar.dModulo * cos(unComplejo.stPolar.dArgumento);
}

/******************************************************************************/
/* Funcion: calcularParteReal                                                 */
/* Descripcion: dado un complejo en forma polar, calcula la parte imaginaria  */
/*               de la forma binomica.                                        */
/* Precondiciones:                                                            */
/******************************************************************************/
double calcularParteImaginaria(tComplejo unComplejo) {
	return unComplejo.stPolar.dModulo * sin(unComplejo.stPolar.dArgumento);
}

/******************************************************************************/
/* Funcion: pasarAGrados                                                      */
/* Descripcion: dado un argumento en radianes, devuelve el mismo en grados.   */
/* Precondiciones:                                                            */
/******************************************************************************/
double pasarAGrados(double unArgumento) {
	return 180 * unArgumento / PI;
}

/******************************************************************************/
/* Funcion: pasarABinomica                                                    */
/* Descripcion: pasa un complejo a forma binomica.                            */
/* Precondiciones:                                                            */
/******************************************************************************/
tComplejo *pasarABinomica(tComplejo *unComplejo) {
	tComplejo *complejoBinomico;

	if ((complejoBinomico=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoBinomico->stBinomica.dReal = calcularParteReal(*unComplejo);
	complejoBinomico->stBinomica.dImaginaria = calcularParteImaginaria(*unComplejo);

	return complejoBinomico;
}

/******************************************************************************/
/* Funcion: pasarAPolar                                                       */
/* Descripcion: pasa un complejo a forma polar.                               */
/* Precondiciones:                                                            */
/******************************************************************************/
tComplejo *pasarAPolar(tComplejo *unComplejo) {
	tComplejo *complejoPolar;

	if ((complejoPolar=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoPolar->stPolar.dModulo = calcularModulo(*unComplejo);
	complejoPolar->stPolar.dArgumento = calcularArgumento(*unComplejo);

	return complejoPolar;
}

/******************************************************************************/
/* Funcion: sumar                                                             */
/* Descripcion: devuelve la suma de dos complejos.                            */
/* Precondiciones:                                                            */
/******************************************************************************/
tComplejo *sumar(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *resultado;

	if (esPolar(unComplejo))
		unComplejo=pasarABinomica(unComplejo);

	if (esPolar(otroComplejo))
		otroComplejo=pasarABinomica(otroComplejo);

	resultado=sumarBinomicos(unComplejo, otroComplejo);

	return resultado;
}

/******************************************************************************/
/* Funcion: sumarBinomicos                                                    */
/* Descripcion: devuelve la suma de dos complejos en forma binomica.          */
/* Precondiciones: los complejos a sumar deben estar en forma binomica.       */
/******************************************************************************/
tComplejo *sumarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoResultante->stBinomica.dReal = unComplejo->stBinomica.dReal
			                             + otroComplejo->stBinomica.dReal;

	complejoResultante->stBinomica.dImaginaria = unComplejo->stBinomica.dImaginaria
			                                   + otroComplejo->stBinomica.dImaginaria;

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: restar                                                            */
/* Descripcion: devuelve la resta de dos complejos.                           */
/* Precondiciones:                                                            */
/******************************************************************************/
tComplejo *restar(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *resultado;

	if (esPolar(unComplejo))
		unComplejo=pasarABinomica(unComplejo);

	if (esPolar(otroComplejo))
		otroComplejo=pasarABinomica(otroComplejo);

	resultado=restarBinomicos(unComplejo, otroComplejo);

	return resultado;
}

/******************************************************************************/
/* Funcion: restarBinomicos                                                   */
/* Descripcion: devuelve la resta de dos complejos en forma binomica.         */
/* Precondiciones: los complejos a restar deben estar en forma binomica.      */
/******************************************************************************/
tComplejo *restarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoResultante->stBinomica.dReal = unComplejo->stBinomica.dReal
			                             - otroComplejo->stBinomica.dReal;

	complejoResultante->stBinomica.dImaginaria = unComplejo->stBinomica.dImaginaria
			                                   - otroComplejo->stBinomica.dImaginaria;

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: multiplicar                                                       */
/* Descripcion: devuelve la multiplicacion de dos complejos.                  */
/* Precondiciones: ambos complejos deben estar expresados de la misma forma.  */
/******************************************************************************/
tComplejo *multiplicar(tComplejo *unComplejo, tComplejo *otroComplejo) {

	if (esPolar(unComplejo) && esPolar(otroComplejo))
		return multiplicarPolares(unComplejo, otroComplejo);
	else
		return multiplicarBinomicos(unComplejo, otroComplejo);

}

/******************************************************************************/
/* Funcion: multiplicarBinomicos                                              */
/* Descripcion: devuelve la multiplicacion de dos complejos binomicos.        */
/* Precondiciones: los complejos a multiplicar deben estar en forma binomica. */
/******************************************************************************/
tComplejo *multiplicarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoResultante->stBinomica.dReal = (unComplejo->stBinomica.dReal *
			                                otroComplejo->stBinomica.dReal)
			                             - (unComplejo->stBinomica.dImaginaria *
			                                otroComplejo->stBinomica.dImaginaria);

	complejoResultante->stBinomica.dImaginaria = (unComplejo->stBinomica.dReal *
			                                      otroComplejo->stBinomica.dImaginaria)
			                                   + (unComplejo->stBinomica.dImaginaria *
			                                	  otroComplejo->stBinomica.dReal);

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: multiplicarPolares                                                */
/* Descripcion: devuelve la multiplicacion de dos complejos polares.          */
/* Precondiciones: los complejos a multiplicar deben estar en forma polar.    */
/******************************************************************************/
tComplejo *multiplicarPolares(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoResultante->stPolar.dModulo = unComplejo->stPolar.dModulo
			                            * otroComplejo->stPolar.dModulo;

	complejoResultante->stPolar.dArgumento = unComplejo->stPolar.dArgumento
			                               + otroComplejo->stPolar.dArgumento;

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: dividir                                                           */
/* Descripcion: devuelve la dividision de dos complejos.                      */
/* Precondiciones: ambos complejos deben estar expresados de la misma forma.  */
/******************************************************************************/
tComplejo *dividir(tComplejo *unComplejo, tComplejo *otroComplejo) {

	if (esPolar(unComplejo) && esPolar(otroComplejo))
		return dividirPolares(unComplejo, otroComplejo);
	else
		return dividirBinomicos(unComplejo, otroComplejo);

}

/******************************************************************************/
/* Funcion: dividirBinomicos                                                  */
/* Descripcion: devuelve la division de dos complejos binomicos.              */
/* Precondiciones: los complejos a dividir deben estar en forma binomica.     */
/******************************************************************************/
tComplejo *dividirBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante, *numerador, *conjugado;
	double denominador;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	conjugado = obtenerConjugado(otroComplejo);

	numerador = multiplicarBinomicos(unComplejo, conjugado);

	denominador = pow(calcularModulo(*otroComplejo), 2);

	complejoResultante->stBinomica.dReal = numerador->stBinomica.dReal
			                             / denominador;

	complejoResultante->stBinomica.dImaginaria = numerador->stBinomica.dImaginaria
			                                   / denominador;

	free(numerador);
    free(conjugado);

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: dividirPolares                                                    */
/* Descripcion: devuelve la division de dos complejos polares.                */
/* Precondiciones: los complejos a dividir deben estar en forma polar.        */
/******************************************************************************/
tComplejo *dividirPolares(tComplejo *unComplejo, tComplejo *otroComplejo) {
	tComplejo *complejoResultante;

	if ((complejoResultante=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	complejoResultante->stPolar.dModulo = unComplejo->stPolar.dModulo
			                            / otroComplejo->stPolar.dModulo;

	complejoResultante->stPolar.dArgumento = unComplejo->stPolar.dArgumento
			                               - otroComplejo->stPolar.dArgumento;

	return complejoResultante;
}

/******************************************************************************/
/* Funcion: potenciar                                                         */
/* Descripcion: devuelve un complejo elevado a una potencia natural.          */
/* Precondiciones:                                                            */
/******************************************************************************/
t_list *potenciar(tComplejo *unComplejo, int potencia) {
	t_list *complejoPotenciado;
	tComplejo *complejoPolar;

	if (esPolar(unComplejo))
	   {
	   complejoPotenciado=deMoivre(unComplejo, potencia);
	   }
	else
	   {
	   complejoPolar=pasarAPolar(unComplejo);
	   complejoPotenciado=deMoivre(complejoPolar, potencia);

	   free(complejoPolar);
	   }

    return complejoPotenciado;
}

/******************************************************************************/
/* Funcion: radicacion                                                        */
/* Descripcion: devuelve la/s raiz/ces n-esima/s de un complejo.              */
/* Precondiciones:                                                            */
/******************************************************************************/
t_list *radicacion(tComplejo *unComplejo, int potencia) {
	t_list *raices;
	tComplejo *complejoPolar;

	if (esPolar(unComplejo))
	   {
		raices=deMoivre(unComplejo, (float) 1/potencia);;
	   }
	else
	   {
	   complejoPolar=pasarAPolar(unComplejo);
	   raices=deMoivre(complejoPolar, (float) 1/potencia);

	   free(complejoPolar);
	   }

    return raices;
}

/******************************************************************************/
/* Funcion: raicesPrimitivas                                                  */
/* Descripcion: devuelve las raices primitivas de un complejo.                */
/* Precondiciones:                                                            */
/******************************************************************************/
t_list *raicesPrimitivas(tComplejo *unComplejo, int orden) {
	t_list *raices, *raicesPrimitivas;
	int totalRaices=0, k=0;

    raices=radicacion(unComplejo, orden);

    totalRaices=list_size(raices);

    raicesPrimitivas=list_create();

    for(k=0; k < totalRaices; k++) {
    	if (maximoComunDivisor(k, totalRaices) == 1)
    		list_add(raicesPrimitivas, list_get(raices, k));
    }
    return raicesPrimitivas;
}

/******************************************************************************/
/* Funcion: maximoComunDivisor                                                */
/* Descripcion: devuelve el mcd de dos numeros.                               */
/* Precondiciones:                                                            */
/******************************************************************************/
int maximoComunDivisor(int unNumero, int otroNumero) {
	int resto = unNumero % otroNumero;

	while (resto > 0) {

		unNumero = otroNumero;
		otroNumero = resto;
		resto = unNumero % otroNumero;
	}

	return otroNumero;
}

/******************************************************************************/
/* Funcion: deMoivre                                                          */
/* Descripcion: calcula la potencia o radicacion de un complejo en forma polar*/
/*              mediante la formula de De Moivre.                             */
/* Precondiciones: el complejo dado debe estar en forma polar.                */
/******************************************************************************/
t_list *deMoivre(tComplejo *unComplejo, float potencia) {
	t_list *resultado;
	tComplejo *raiz;
	int k, maximo;

	resultado=list_create();

	if (potencia < 1)
	   maximo = ceil(1/potencia);
	else
	   {
		// Devuelvo el complejo elevado a la potencia recibida por parametro
		if ((raiz=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
			return NULL;
		}

	   raiz->stPolar.dModulo = pow(unComplejo->stPolar.dModulo, potencia);
	   raiz->stPolar.dArgumento = unComplejo->stPolar.dArgumento * potencia;
	   list_add(resultado, raiz);

	   return resultado;
	   }

	// Devuelvo las "maximo - 1" raices del complejo
	for (k=0; k < maximo; k++) {

		if ((raiz=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
			return NULL;
		}

		raiz->stPolar.dModulo = pow(unComplejo->stPolar.dModulo, potencia);
		raiz->stPolar.dArgumento = (unComplejo->stPolar.dArgumento + 2 * k * PI) / maximo;

		list_add(resultado, raiz);
	}

	return resultado;
}

/******************************************************************************/
/* Funcion: conjugado                                                         */
/* Descripcion: devuelve el conjugado de un complejo dado.                    */
/* Precondiciones: el complejo dado debe estar en forma binomica.             */
/******************************************************************************/
tComplejo *obtenerConjugado(tComplejo *unComplejo) {
	tComplejo *conjugado;

	if ((conjugado=(tComplejo *)calloc(1, sizeof(tComplejo))) == NULL) {
		return NULL;
	}

	conjugado->stBinomica.dReal = unComplejo->stBinomica.dReal;

	conjugado->stBinomica.dImaginaria = unComplejo->stBinomica.dImaginaria * -1;

	return conjugado;
}

/******************************************************************************/
/* Funcion: esPolar                                                           */
/* Descripcion: devuelve si un complejo esta en forma polar o no.             */
/* Precondiciones:                                                            */
/******************************************************************************/
int esPolar(tComplejo *unComplejo) {
	return unComplejo->stPolar.dModulo >= 1;
}
