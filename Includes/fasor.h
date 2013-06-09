/*
============================================================================
 Name        : fasor.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Definiciones de las operaciones con fasores.
 Version     :
 ============================================================================
 */
#ifndef FASOR_H_
#define FASOR_H_

#include <stdlib.h>
#include <string.h>
#include "complejo.h"

typedef struct
{
	int iFuncion;
	double dFrecuencia;
	double dFase;
	double dAmplitud;
} tFasor;

tFasor *sumaFasores(tFasor fasor1, tFasor fasor2);
tComplejo pasarFasorAComplejo(tFasor *fasor);
tFasor *pasarComplejoAFasor(tComplejo *z, tFasor *fasor);

#endif /* FASOR_H_ */
