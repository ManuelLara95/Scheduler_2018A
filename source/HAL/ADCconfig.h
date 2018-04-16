/*
 * ADC_init.h
 *
 *  Created on: Apr 10, 2018
 *      Author: Manuel
 */

#ifndef ADCINIT_H_
#define ADCINIT_H_
/********************* INCLUSIONES ******************** */
#include "drivers_HAL/fsl_adc16.h"
#include "fsl_debug_console.h"
#include "source/stdtypedef.h"
#include "source/HAL/PWMconfig.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "board.h"
/********************* DEFINICIONES ******************** */
#define ADC_BASE 						ADC0
#define ADC_CANAL						0U
#define ADC_CANALUSUARIO 				0U 				/*PTE20, ADC0_SE0 */

// Definiciones especificas del selector de modo
#define CHNL0	kTPM_Chnl_0
#define	CHNL1	kTPM_Chnl_1

/********************* DECLARACIONES ******************** */
enum ModoDeOperacion{
	MODO_NORMAL,
	INCREMENTO_NORMAL,
	INCREMENTO_RAPIDO,
	DECREMENTO_NORMAL,
	DECREMENTO_RAPIDO,
	MODO_SEGURO
};

/********************* PROTOTIPADO ******************** */
extern T_UWORD ADCinit_getADCvalue(ADC_Type *base, uint32_t channelGroup);
extern void ADCinit_ADCsetconfig(void);

#endif /* ADCINIT_H_ */
