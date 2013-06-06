/*
 * pantalla.h
 *
 *  Created on: 28/04/2013
 *      Author: Alfredo
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"

void pantalla();
void printMenu();
void opcionSuma();
void opcionResta();
void opcionMultiplicacion();
void opcionDivision();
tComplejo capturaComplejo();
tComplejo capturaFormaBinomica();
tComplejo capturaFormaPolar();
void printResultadoComplejo(tComplejo *z);
void printResultadorPolar(tComplejo *z);
void printResultadorBinomica(tComplejo *z);

#endif /* PANTALLA_H_ */
