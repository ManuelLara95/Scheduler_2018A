/*
 * PWMmiddle.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Manuel
 */

#include "source/MAL/PWMmiddle.h"

T_UBYTE PWMmiddle_setOperationMODE(T_UWORD ADC_VALUE){
	if(ADC_VALUE){
		if( (ADC_VALUE < MAXsafeLimit) && (ADC_VALUE > MINsafeLimit) )
			{
				PWMinit_PWM_setNORMALmode(CHNL0);
				PWMinit_PWM_setNORMALmode(CHNL1);
				return MODO_NORMAL;
			}
		else if( (ADC_VALUE > MAXsafeLimit) && (ADC_VALUE < highDANGERLimit) )
			{
				PWMinit_PWM_NORMALCHANGE(CHNL0);
				PWMinit_PWM_setNORMALmode(CHNL1);
				return INCREMENTO_NORMAL;
			}

		else if(ADC_VALUE > highDANGERLimit)
			{
				PWMinit_PWM_DANGERCHANGE(CHNL0);
				PWMinit_PWM_setNORMALmode(CHNL1);
				return INCREMENTO_RAPIDO;
			}
		else if( (ADC_VALUE < MINsafeLimit) && (ADC_VALUE > lowDANGERlimit) )
			{
				PWMinit_PWM_setNORMALmode(CHNL0);
				PWMinit_PWM_NORMALCHANGE(CHNL1);
				return DECREMENTO_NORMAL;
			}

		else if (ADC_VALUE < lowDANGERlimit)
			{
				PWMinit_PWM_setNORMALmode(CHNL0);
				PWMinit_PWM_DANGERCHANGE(CHNL1);
				return DECREMENTO_RAPIDO;
			}
	}
}
