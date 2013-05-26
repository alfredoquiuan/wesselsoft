#include <stdio.h>
#include <math.h>

struct complejo
{
	double parteReal;
	double parteCompleja;
};

void printBinomial(struct complejo z);
void printPolar(struct complejo z);
double getModulo(struct complejo z);
double getArgumento(struct complejo z);
int getCuandrante(struct complejo z);
double corregirArgumento(double argumento);

int main(void)
{
	struct complejo z = {2.0,-2.0};
	printBinomial(z);
	printPolar(z);
	return 0;
}
void printBinomial(struct complejo z)
{
	printf ("El complejo en forma binomial es: z = %.0lf + %.0lfi", z.parteReal, z.parteCompleja);
}
void printPolar(struct complejo z)
{
	double modulo = getModulo(z);
	double argumento = getArgumento(z)/3.1416;
	printf ("El complejo en forma polar es: z = %.2lf (cos %.2lfpi + sen %.2lfpi", modulo, argumento,argumento);
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
