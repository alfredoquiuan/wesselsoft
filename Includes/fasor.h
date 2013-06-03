/*
 * fasor.h
 *
 *  Created on: 28/04/2013
 *      Author: Alfredo
 */

#ifndef FASOR_H_
#define FASOR_H_

#include <stdlib.h>
#include <string.h>
#include "complejo.h"

typedef struct
{
	char *cFuncion;
	double dFrecuencia;
	double dFase;
	double dAmplitud;
} tFasor;

tFasor sumaFasores(tFasor fasor1, tFasor fasor2);
tComplejo pasarFasorAComplejo(tFasor fasor);
tFasor pasarComplejoAFasor(tComplejo *z, tFasor fasor);

#endif /* FASOR_H_ */
