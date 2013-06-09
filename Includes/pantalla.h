/*
============================================================================
 Name        : pantalla.h
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Definiciones de la interfaz usuario.
 Version     :
 ============================================================================
 */
#ifndef PANTALLA_H_
#define PANTALLA_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "complejo.h"
#include "fasor.h"
#include "transferencia.h"

void pantalla();
void printMenu();
void opcionSuma();
void opcionResta();
void opcionMultiplicacion();
void opcionDivision();
void opcionPotencia();
void opcionRadicacion();
void opcionRaicesPrimitivas();
void opcionSumaFasores();
void opcionTransferencia();
tComplejo capturaComplejo();
tComplejo capturaFormaBinomica();
tComplejo capturaFormaPolar();
int capturaEntero();
tFasor capturaFasor();
int capturaFasorFuncion();
double capturaFasorAmplitud();
double capturaFasorFrecuencia();
double capturaFasorFase();
void printResultadoComplejo(tComplejo *z);
void printResultadoPolar(tComplejo *z);
void printResultadoBinomica(tComplejo *z);
void printResultadoListaComplejos(t_list *resultado);
void printResultadoFasor(tFasor *resultado);
void imprimirRaices(void *unComplejo);
tFasor validarFasor(tFasor fasor, int funcion);

#endif /* PANTALLA_H_ */
