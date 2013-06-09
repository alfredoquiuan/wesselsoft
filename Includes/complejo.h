/*
============================================================================
 Name        : complejo.h
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Definiciones de las funciones con complejos.
 Version     :
 ============================================================================
 */
#ifndef ESTRUC_COMPLEJO_H_
#define ESTRUC_COMPLEJO_H_

#include "list.h"

typedef struct
{
	double dReal;
	double dImaginaria;
} tBinomica;

typedef struct
{
	double dModulo;
	double dArgumento;
} tPolar;

typedef struct
{
	tBinomica stBinomica;
	tPolar stPolar;
} Complejo;

typedef Complejo tComplejo;

/* Prototipos de funciones que permiten operaciones con complejos */
double calcularModulo(tComplejo);
double calcularArgumento(tComplejo unComplejo);
double calcularParteReal(tComplejo unComplejo);
double calcularParteImaginaria(tComplejo unComplejo);
double pasarAGrados(double unArgumento);
tComplejo *pasarABinomica(tComplejo *unComplejo);
tComplejo *pasarAPolar(tComplejo *unComplejo);
tComplejo *sumar(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *sumarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *restar(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *restarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *multiplicar(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *multiplicarBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *multiplicarPolares(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *dividir(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *dividirBinomicos(tComplejo *unComplejo, tComplejo *otroComplejo);
tComplejo *dividirPolares(tComplejo *unComplejo, tComplejo *otroComplejo);
t_list *potenciar(tComplejo *unComplejo, int potencia);
t_list *radicacion(tComplejo *unComplejo, int potencia);
t_list *raicesPrimitivas(tComplejo *unComplejo, int orden);
int maximoComunDivisor(int unNumero, int otroNumero);
t_list *deMoivre(tComplejo *unComplejo, float potencia);
tComplejo *obtenerConjugado(tComplejo *unComplejo);
int esPolar(tComplejo *unComplejo);

#endif /* ESTRUC_COMPLEJO_H_ */
