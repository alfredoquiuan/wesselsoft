/*
============================================================================
 Name        : fasor.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Funciones que realizan operaciones con fasores.
 Version     :
 ============================================================================
 */

#include "fasor.h"

tFasor *sumaFasores(tFasor fasor1, tFasor fasor2){
	tFasor *resultado;
	tComplejo w1 = pasarFasorAComplejo(&fasor1);
	tComplejo w2 = pasarFasorAComplejo(&fasor2);
	tComplejo *z = sumar(&w1,&w2);
	resultado = pasarComplejoAFasor(z,&fasor1);
	return resultado;
}

tComplejo pasarFasorAComplejo(tFasor *fasor)
{
	tComplejo z;
	z.stPolar.dModulo = fasor->dAmplitud;
	z.stPolar.dArgumento = fasor->dFase;
	return z;
}

tFasor *pasarComplejoAFasor(tComplejo *z, tFasor *fasor)
{
	tFasor *f;
	tComplejo *w = pasarAPolar(z);

	if ((f=(tFasor *)calloc(1, sizeof(tFasor))) == NULL) {
		return NULL;
	}

	f->iFuncion = fasor->iFuncion;
	f->dAmplitud = w->stPolar.dModulo;
	f->dFrecuencia = fasor->dFrecuencia;
	f->dFase = w->stPolar.dArgumento;
	free(w);
	return f;
}
