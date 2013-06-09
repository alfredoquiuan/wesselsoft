/*
============================================================================
 Name        : trasnferencia.h
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Definiciones de la funcion trasnferencia.
 Version     :
 ============================================================================
 */
#ifndef TRANSFERENCIA_H_
#define TRANSFERENCIA_H_

#include "complejo.h"
#include "list.h"

tComplejo transferencia(t_list *ceros, t_list *polos, double k, tComplejo punto);



#endif /* TRANSFERENCIA_H_ */
