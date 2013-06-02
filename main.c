/*
 * main.c
 *
 *  Created on: 26/05/2013
 *      Author: familia
 */

#include "complejo.h"

int main(void)
{
	struct complejo z;
	z.parteReal = 2.0;
	z.parteCompleja = 2.0;
	printBinomial(z);
	printPolar(z);
	struct complejo w;
	w.modulo = 1;
	w.argumento = 3.1416 / 4;
	printBinomial(getBinomial(w));
	printBinomial(suma(z,w));
	struct complejo x;
	x.parteReal = 0;
	x.parteCompleja = -8;
	radicacion(getPolar(x),3);
	return 0;
}
