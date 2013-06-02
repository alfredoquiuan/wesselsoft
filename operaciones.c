/*
 * operaciones.c
 *
 *  Created on: 26/05/2013
 *      Author: Alfredo Quiuan
 */
#include "operaciones.h"

struct complejo suma(struct complejo z1, struct complejo z2)
{
	struct complejo w;
	w.parteReal = z1.parteReal + z2.parteReal;
	w.parteCompleja = z1.parteCompleja + z2.parteCompleja;
	return w;
}
struct complejo resta(struct complejo z1, struct complejo z2)
{
	struct complejo w;
	w.parteReal = z1.parteReal - z2.parteReal;
	w.parteCompleja = z1.parteCompleja - z2.parteCompleja;
	return w;
}
struct complejo multiplicacion(struct complejo z1, struct complejo z2)
{
	struct complejo w;
	w.parteReal = z1.parteReal * z2.parteReal - z1.parteCompleja * z2.parteCompleja;
	w.parteCompleja = z1.parteReal * z2.parteCompleja + z2.parteReal * z1.parteCompleja;
	return w;
}
struct complejo division(struct complejo z1, struct complejo z2)
{
	struct complejo w;
	double wDenominador = pow(getModulo(z2),2);
	//struct complejo wNumerador = multipliacacion(z1,getComplemento(z2));
	//w.parteReal = wNumerador.parteReal / wDenominador;
	//w.parteCompleja = wNumerador.parteCompleja / wDenominador;
	return w;
}
struct complejo potencia(struct complejo z, int potencia)
{
	struct complejo w;
	w.modulo = pow(z.modulo,potencia);
	w.argumento = potencia * z.argumento;
	return w;
}
struct complejo radicacion(struct complejo z, int raiz)
{
	struct complejo w;
	w.modulo = pow(z.modulo,1/raiz);
	int i;
	for (i=0;i<raiz;i++) {
		w.argumento = moivre(z.argumento,i,raiz);
		printf ("El complejo en forma polar es: z = %.2lf (cos %.2lfpi + sen %.2lfpi)\n", w.modulo, w.argumento,w.argumento);
	//w.argumento = (z.argumento + 2kpi)/ potencia;
	}

	return w;
}

double moivre(double angulo,int k, int n)
{
	return (angulo * 3.1416 + (2 * k * 3.1416))/n;
}
