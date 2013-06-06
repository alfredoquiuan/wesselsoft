/*
 ============================================================================
 Name        : wesselsoft.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban ...
 Description : Programa principal del sistema Wesselsoft.
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "complejo.h"
#include "list.h"
#include "fasor.h"
#include "pantalla.h"

int testsFormaBinomica();
int testsFormaPolar();
int testsOperacionesBasicas();
int testsOperacionesAvanzadas();
int testFasores();
void imprimirRaices(void *unComplejo);

int main(void) {
	pantalla();
	return EXIT_SUCCESS;
}

int testsFormaBinomica() {
	tComplejo complejo1;
	char modulo[5], raiz[5];

	complejo1.stBinomica.dReal = 2;
	complejo1.stBinomica.dImaginaria = 2;

//	printf("Modulo complejo1: %.2f \n", calcularModulo(complejo1));
//	printf("Raiz cuadrada de 8: %.2f \n", sqrt(8));
	sprintf(modulo, "%.2f", calcularModulo(complejo1));
	sprintf(raiz, "%.2f", sqrt(8));
	assert(strcmp(modulo, raiz) == 0);

	complejo1.stBinomica.dReal = 0;
	complejo1.stBinomica.dImaginaria = 0;

//	printf("Modulo complejo1: %.2f \n", calcularModulo(complejo1));
//	printf("Raiz cuadrada de 8: %.2f \n", sqrt(0));
	sprintf(modulo, "%.2f", calcularModulo(complejo1));
	sprintf(raiz, "%.2f", sqrt(0));
	assert(strcmp(modulo, raiz) == 0);

	complejo1.stBinomica.dReal = -4;
	complejo1.stBinomica.dImaginaria = -4;

//	printf("Modulo complejo1: %.2f \n", calcularModulo(complejo1));
//	printf("Raiz cuadrada de 8: %.2f \n", sqrt(0));
	sprintf(modulo, "%.2f", calcularModulo(complejo1));
	sprintf(raiz, "%.2f", sqrt(32));
	assert(strcmp(modulo, raiz) == 0);

	return EXIT_SUCCESS;
}

int testsFormaPolar() {
	tComplejo complejo1, complejo2;
	char real[8], imaginaria[8];

	complejo1.stPolar.dModulo = 5;
	complejo1.stPolar.dArgumento = 0.785398;

	complejo2.stBinomica.dReal = calcularParteReal(complejo1);
	complejo2.stBinomica.dImaginaria = calcularParteImaginaria(complejo1);

	sprintf(real, "%.4f", complejo2.stBinomica.dReal);
	sprintf(imaginaria, "%.4f", complejo2.stBinomica.dImaginaria);
	assert(strcmp(real, imaginaria) == 0);

	complejo1.stPolar.dModulo = 8;
	complejo1.stPolar.dArgumento = 4.712389;

	complejo2.stBinomica.dReal = calcularParteReal(complejo1);
	complejo2.stBinomica.dImaginaria = calcularParteImaginaria(complejo1);

	assert(floor(complejo2.stBinomica.dReal) == 0);
	assert(floor(complejo2.stBinomica.dImaginaria) == -8);

	complejo1.stPolar.dModulo = 0;
	complejo1.stPolar.dArgumento = 0;

	complejo2.stBinomica.dReal = calcularParteReal(complejo1);
	complejo2.stBinomica.dImaginaria = calcularParteImaginaria(complejo1);

	assert(floor(complejo2.stBinomica.dReal) == floor(complejo2.stBinomica.dImaginaria));

	complejo1.stPolar.dModulo = -1;
	complejo1.stPolar.dArgumento = -1;

	complejo2.stBinomica.dReal = calcularParteReal(complejo1);
	complejo2.stBinomica.dImaginaria = calcularParteImaginaria(complejo1);

	sprintf(real, "%.4f", complejo2.stBinomica.dReal);
	sprintf(imaginaria, "%.4f", complejo2.stBinomica.dImaginaria);
	assert(strcmp(real, "-0.5403") == 0);
	assert(strcmp(imaginaria, "0.8415") == 0);

	complejo1.stBinomica.dReal = -1;
	complejo1.stBinomica.dImaginaria = sqrt(3);

	assert(ceil(pasarAGrados(calcularArgumento(complejo1))) == 120);

	complejo1.stBinomica.dReal = 0;
	complejo1.stBinomica.dImaginaria = -8;

	assert(ceil(pasarAGrados(calcularArgumento(complejo1))) == 270);

	return EXIT_SUCCESS;
}

int testsOperacionesBasicas() {
	tComplejo binomico1, binomico2, *resultadoBinomico, *polar1, *polar2, *resultadoPolar;
	char real[8], imaginaria[8];

	/*------------------------------*/
	/*    TEST EN FORMA BINOMICA    */
	/*------------------------------*/
	binomico1.stBinomica.dReal = 2;
	binomico1.stBinomica.dImaginaria = 5;

	binomico2.stBinomica.dReal = 3;
	binomico2.stBinomica.dImaginaria = -4;

	resultadoBinomico = sumar(&binomico1, &binomico2);

	printf("%.4f%+.4f j\n", resultadoBinomico->stBinomica.dReal, resultadoBinomico->stBinomica.dImaginaria);
    assert(floor(resultadoBinomico->stBinomica.dReal) == 5);
    assert(floor(resultadoBinomico->stBinomica.dImaginaria) == 1);
    free(resultadoBinomico);

	resultadoBinomico = restar(&binomico1, &binomico2);

	printf("%.4f%+.4f j\n", resultadoBinomico->stBinomica.dReal, resultadoBinomico->stBinomica.dImaginaria);
    assert(floor(resultadoBinomico->stBinomica.dReal) == -1);
    assert(floor(resultadoBinomico->stBinomica.dImaginaria) == 9);
    free(resultadoBinomico);

	resultadoBinomico = multiplicar(&binomico1, &binomico2);

	printf("%.4f%+.4f j\n", resultadoBinomico->stBinomica.dReal, resultadoBinomico->stBinomica.dImaginaria);
    assert(floor(resultadoBinomico->stBinomica.dReal) == 26);
    assert(floor(resultadoBinomico->stBinomica.dImaginaria) == 7);
    free(resultadoBinomico);

	resultadoBinomico = dividir(&binomico1, &binomico2);

	printf("%.4f%+.4f j\n", resultadoBinomico->stBinomica.dReal, resultadoBinomico->stBinomica.dImaginaria);
	sprintf(real, "%.4f", resultadoBinomico->stBinomica.dReal);
	sprintf(imaginaria, "%.4f", resultadoBinomico->stBinomica.dImaginaria);
	assert(strcmp(real, "-0.5600") == 0);
	assert(strcmp(imaginaria, "0.9200") == 0);
    free(resultadoBinomico);


	/*---------------------------*/
	/*    TEST EN FORMA POLAR    */
	/*---------------------------*/
	polar1 = pasarAPolar(&binomico1);
	polar2 = pasarAPolar(&binomico2);

	resultadoPolar = sumar(polar1, polar2);

	printf("%.4f%+.4f j\n", resultadoPolar->stBinomica.dReal, resultadoPolar->stBinomica.dImaginaria);
	sprintf(real, "%.4f", resultadoPolar->stBinomica.dReal);
	sprintf(imaginaria, "%.4f", resultadoPolar->stBinomica.dImaginaria);
	assert(strcmp(real, "5.0000") == 0);
	assert(strcmp(imaginaria, "1.0000") == 0);
    free(resultadoPolar);

    resultadoPolar = restar(polar1, polar2);

	printf("%.4f%+.4f j\n", resultadoPolar->stBinomica.dReal, resultadoPolar->stBinomica.dImaginaria);
	sprintf(real, "%.4f", resultadoPolar->stBinomica.dReal);
	sprintf(imaginaria, "%.4f", resultadoPolar->stBinomica.dImaginaria);
	assert(strcmp(real, "-1.0000") == 0);
	assert(strcmp(imaginaria, "9.0000") == 0);
    free(resultadoPolar);

    resultadoPolar = multiplicar(polar1, polar2);

	printf("%.4f%+.4f j\n", resultadoPolar->stPolar.dModulo, resultadoPolar->stPolar.dArgumento);
	sprintf(real, "%.4f", resultadoPolar->stPolar.dModulo);
	sprintf(imaginaria, "%.4f", resultadoPolar->stPolar.dArgumento);
	assert(strcmp(real, "26.9258") == 0);
	assert(strcmp(imaginaria, "0.2630") == 0);
    free(resultadoPolar);

    resultadoPolar = dividir(polar1, polar2);

	printf("%.4f%+.4f j\n", resultadoPolar->stPolar.dModulo, resultadoPolar->stPolar.dArgumento);
	sprintf(real, "%.4f", resultadoPolar->stPolar.dModulo);
	sprintf(imaginaria, "%.4f", resultadoPolar->stPolar.dArgumento);
	assert(strcmp(real, "1.0770") == 0);
	assert(strcmp(imaginaria, "2.1176") == 0);
    free(resultadoPolar);

	return EXIT_SUCCESS;
}

int testsOperacionesAvanzadas() {
	tComplejo binomico1, polar1, *complejo;
	t_list *resultado;
	char real[10], imaginaria[10];

    binomico1.stBinomica.dReal = 3;
    binomico1.stBinomica.dImaginaria = -4;

	resultado = potenciar(&binomico1, 3);

	complejo = pasarABinomica((tComplejo *) resultado->head->data);
	printf("%.4f%+.4f j\n", complejo->stBinomica.dReal, complejo->stBinomica.dImaginaria);
	sprintf(real, "%.4f", complejo->stBinomica.dReal);
	sprintf(imaginaria, "%.4f", complejo->stBinomica.dImaginaria);
	assert(strcmp(real, "-117.0000") == 0);
	assert(strcmp(imaginaria, "-44.0000") == 0);
	list_destroy(resultado);

    polar1.stPolar.dModulo = 3;
    polar1.stPolar.dArgumento = 0.523598775;

	resultado = potenciar(&polar1, 5);

	complejo = (tComplejo *) resultado->head->data;
	printf("[%.4f, %.4f]\n", complejo->stPolar.dModulo, complejo->stPolar.dArgumento);
	sprintf(real, "%.4f", complejo->stPolar.dModulo);
	sprintf(imaginaria, "%.4f", complejo->stPolar.dArgumento);
	assert(strcmp(real, "243.0000") == 0);
	assert(strcmp(imaginaria, "2.6180") == 0);
	list_destroy(resultado);

    binomico1.stBinomica.dReal = 0;
    binomico1.stBinomica.dImaginaria = -8;

	resultado = radicacion(&binomico1, 3);

	list_iterate(resultado, imprimirRaices);

	assert(list_size(resultado) == 3);
	list_destroy(resultado);

    binomico1.stBinomica.dReal = 1;
    binomico1.stBinomica.dImaginaria = 0;

	resultado = radicacion(&binomico1, 6);

	list_iterate(resultado, imprimirRaices);
	list_destroy(resultado);

    binomico1.stBinomica.dReal = 1;
    binomico1.stBinomica.dImaginaria = 0;

	resultado = raicesPrimitivas(&binomico1, 6);

	list_iterate(resultado, imprimirRaices);
	list_destroy(resultado);

	return EXIT_SUCCESS;
}

int testFasores()
{
	tFasor fasor1, fasor2, resultado;
	fasor1.cFuncion = "cos";
	fasor1.dAmplitud = 4;
	fasor1.dFrecuencia = 3;
	fasor1.dFase = 3.1416/4;
	fasor2.cFuncion = "cos";
	fasor2.dAmplitud = 6;
	fasor2.dFrecuencia = 3;
	fasor2.dFase = -3.1416/3;
	resultado = sumaFasores(fasor1,fasor2);
	assert(strcmp(resultado.cFuncion,"cos") == 0);
	double dAmplitud= floor(resultado.dAmplitud * 100) / 100;
	assert(dAmplitud == 6.29);
	assert(resultado.dFrecuencia == 3.00);
	double dFase = floor(resultado.dFase * 100) / 100;
	assert(dFase == -0.39);

	return EXIT_SUCCESS;
}

void imprimirRaices(void *unComplejo) {

	tComplejo *raiz;

	raiz = (tComplejo *) unComplejo;

	printf("[%.4f, %.4f]\n", raiz->stPolar.dModulo, raiz->stPolar.dArgumento);
}
