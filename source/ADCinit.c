/*
 * ADC_init.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Manuel Lara
 */
/********************* INCLUSIONES ******************** */
#include "drivers_HAL/fsl_adc16.h"
#include "fsl_debug_console.h"
#include "source/stdtypedef.h"
#include "source/ADCinit.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "board.h"

/********************* DEFINICIONES ******************** */
#define ADC_BASE 						ADC0
#define ADC_CANAL						0U
#define ADC_CANALUSUARIO 				0U 				/*PTE20, ADC0_SE0 */

// Definiciones especificas del selector de modo
#define TOLERANCIAincrementoNORMAL		80		// +10°
#define TOLERANCIAincrementoRAPIDO		160		// +20°

#define TOLERANCIAdecrementoNORMAL		40		// -5°
#define TOLERANCIAdecrementoRAPIDO		80		// -10°
#define VALORDETEMPERATURAbase			245		// A 30°

#define TOPEINCREMENTOnormal		VALORDETEMPERATURAbase + TOLERANCIAincrementoNORMAL
#define TOPEINCREMENTOrapido		VALORDETEMPERATURAbase + TOLERANCIAincrementoRAPIDO
#define TOPEDECREMENTOnormal		VALORDETEMPERATURAbase - TOLERANCIAdecrementoNORMAL
#define TOPEDECREMENTOrapido		VALORDETEMPERATURAbase - TOLERANCIAdecrementoRAPIDO
/********************* DECLARACIONES ******************** */
volatile T_UWORD ADC_ValorLeido;
adc16_config_t ADC_EstructuraConfiguracion;
adc16_channel_config_t ADC_EstructuraConfiguraciondelCanal;

enum ModoDeOperacion{
	MODO_NORMAL,
	INCREMENTO_NORMAL,
	INCREMENTO_RAPIDO,
	DECREMENTO_NORMAL,
	DECREMENTO_RAPIDO,
	MODO_SEGURO
};
/********************* FUNCIONES/CÓDIGO ******************** */
/*!
 * @brief Main function
 */
void ADCinit_ADCconfig(void){
	ADC_EstructuraConfiguracion.referenceVoltageSource = kADC16_ReferenceVoltageSourceVref;
    ADC_EstructuraConfiguracion.clockSource = kADC16_ClockSourceAsynchronousClock;
    ADC_EstructuraConfiguracion.enableAsynchronousClock = true;
    ADC_EstructuraConfiguracion.clockDivider = kADC16_ClockDivider8;
    ADC_EstructuraConfiguracion.resolution = kADC16_Resolution12or13Bit;
    ADC_EstructuraConfiguracion.longSampleMode = kADC16_LongSampleDisabled;
    ADC_EstructuraConfiguracion.enableHighSpeed = false;
    ADC_EstructuraConfiguracion.enableLowPower = false;
    ADC_EstructuraConfiguracion.enableContinuousConversion = false;
	ADC_EstructuraConfiguracion.referenceVoltageSource = kADC16_ReferenceVoltageSourceValt;

	ADC16_Init(ADC_BASE, &ADC_EstructuraConfiguracion);
	ADC16_EnableHardwareTrigger(ADC_BASE, false); 				/* Evitar muestreo por hardware */

	ADC_EstructuraConfiguraciondelCanal.channelNumber = ADC_CANALUSUARIO;
	ADC_EstructuraConfiguraciondelCanal.enableInterruptOnConversionCompleted = TRUE; /* Enable the interrupt. */
	ADC_EstructuraConfiguraciondelCanal.enableDifferentialConversion = FALSE;
}

/*!
 * @brief function int getADCValue
 * @param base: ADC number, channelGroup: ADC Channel to be read
 * @return: unsigned 32 bits int
 */
T_UWORD ADCinit_getADCvalue(ADC_Type *base, uint32_t channelGroup){
	ADC16_SetChannelConfig(ADC_BASE, ADC_CANAL, &ADC_EstructuraConfiguraciondelCanal);

	return base->R[channelGroup];
}

T_UBYTE ADCinit_setOperationMODE(T_UWORD ADC_VALUE){
	if( (ADC_VALUE < TOPEINCREMENTOnormal) && (ADC_VALUE > TOPEDECREMENTOnormal ))
		return MODO_NORMAL;

	else if( (ADC_VALUE > TOPEINCREMENTOnormal) && (ADC_VALUE < TOPEINCREMENTOrapido) )
		return INCREMENTO_NORMAL;
	else if( (ADC_VALUE > TOPEINCREMENTOrapido) )
		return INCREMENTO_RAPIDO;

	else if( (ADC_VALUE < TOPEDECREMENTOnormal) && (ADC_VALUE > TOPEDECREMENTOrapido) )
		return DECREMENTO_NORMAL;
	else if ( ADC_VALUE < TOPEDECREMENTOrapido)
		return DECREMENTO_RAPIDO;
}
