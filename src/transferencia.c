/*
============================================================================
 Name        : transferencia.c
 Author      : Javier de Innocenti
               Alfredo Quiuan
               Esteban Taylor
 Description : Funciones que realizan calculo de la funcion transferencia.
 Version     :
 ============================================================================
 */
#include "transferencia.h"

tComplejo transferencia(t_list *ceros, t_list *polos, double k, tComplejo punto)
{
	tComplejo dividendo, divisor, resultado;

	//Obtenemos el dividendo de la función
	if (list_is_empty(ceros)){
		dividendo.stBinomica.dReal = k;
		dividendo.stBinomica.dImaginaria = 0;
	} else {
		dividendo = *restar(&punto, (tComplejo *) list_remove(ceros, 0));
		while (list_is_empty(ceros) == 0 ){                    //mientras que la lista no este vacía
			dividendo = *multiplicar(restar(&punto,(tComplejo *) list_remove(ceros, 0)), &dividendo);
		};
		dividendo.stBinomica.dReal = dividendo.stBinomica.dReal * k;
		dividendo.stBinomica.dImaginaria = dividendo.stBinomica.dImaginaria * k;
	};
	//Obtenemos el divisor de la función
	divisor = *restar(&punto, (tComplejo *) list_remove(polos, 0));
	while (list_is_empty(polos) == 0 ){                    //mientras que la lista no este vacía
		divisor = *multiplicar(restar(&punto, (tComplejo *) list_remove(polos, 0)), &divisor);
		};
	//Obtenemos el resultado
	resultado = *dividir(&dividendo, &divisor);
	return resultado;
}

