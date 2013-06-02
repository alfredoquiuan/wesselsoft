/*
 * operaciones.h
 *
 *  Created on: 26/05/2013
 *      Author: familia
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include "complejo.h"

struct complejo suma(struct complejo z, struct complejo w);
struct complejo radicacion(struct complejo z, int raiz);
double moivre(double angulo,int k, int n);
#endif /* OPERACIONES_H_ */
