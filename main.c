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
	return 0;
}
