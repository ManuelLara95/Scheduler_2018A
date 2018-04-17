/*
 * ADCmiddle.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Manuel
 */

#include "source/MAL/ADCmiddle.h"

T_UWORD VALOR_ADC = 0;

extern T_UBYTE ADCmiddle_getTemperature(void){
	VALOR_ADC = ADCinit_getADCvalue(ADC0, CHNL0);
	VALOR_ADC = ((3.3*VALOR_ADC*100)/4095);
	return VALOR_ADC;
}
