#ifndef COMPLEJO_H_
#define COMPLEJO_H_

#include <stdio.h>
#include <math.h>
#include "operaciones.h"

struct complejo
{
	double parteReal;
	double parteCompleja;
	double modulo;
	double argumento;
};

void printBinomial(struct complejo z);
void printPolar(struct complejo z);
struct complejo getPolar(struct complejo z);
struct complejo getBinomial(struct complejo z);
double getModulo(struct complejo z);
double getArgumento(struct complejo z);
int getCuandrante(struct complejo z);
double corregirArgumento(double argumento);

#endif /* COMPLEJO_H_ */
