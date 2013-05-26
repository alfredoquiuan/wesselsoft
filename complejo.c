#include "complejo.h"

void printBinomial(struct complejo z)
{
	printf ("El complejo en forma binomial es: z = %.0lf + %.0lfi\n", z.parteReal, z.parteCompleja);
}
void printPolar(struct complejo z)
{
	struct complejo w = getPolar(z);
	printf ("El complejo en forma polar es: z = %.2lf (cos %.2lfpi + sen %.2lfpi)\n", w.modulo, w.argumento,w.argumento);
}
struct complejo getPolar(struct complejo z)
{
	z.modulo = getModulo(z);
	z.argumento = getArgumento(z)/3.1416;
	return z;
}
struct complejo getBinomial(struct complejo z)
{
	z.parteReal = cos(z.argumento) * z.modulo;
	z.parteCompleja = sin(z.argumento) * z.modulo;
	return z;
}
double getModulo(struct complejo z)
{
	return sqrt(pow(z.parteReal,2.0) + pow(z.parteCompleja, 2.0));
}
double getArgumento(struct complejo z)
{
	double argumento;
	if (getCuandrante(z)) {
		argumento = atan2(z.parteCompleja,z.parteReal);
		return corregirArgumento(argumento);
	}
	return 0;
}
int getCuandrante(struct complejo z)
{
	if (z.parteReal == 0 && z.parteCompleja == 0){return 0;}
	if (z.parteReal >= 0 && z.parteCompleja >= 0){return 1;}
	if (z.parteReal <= 0 && z.parteCompleja >= 0){return 2;}
	if (z.parteReal <= 0 && z.parteCompleja <= 0){return 3;}
	if (z.parteReal >= 0 && z.parteCompleja <= 0){return 4;}
	return 0;
}
double corregirArgumento(double argumento)
{
	if (argumento < 0){
		return 2 * 3.1416 + argumento;
	}
	return argumento;
}
struct complejo getComplemento(struct complejo z)
{
	struct complejo w;
	w.parteReal = z.parteReal;
	w.parteCompleja = 0 - z.parteCompleja;
	return w;
}
