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

/********************* DECLARACIONES ******************** */
volatile T_UWORD ADC_ValorLeido;
adc16_config_t ADC_EstructuraConfiguracion;
adc16_channel_config_t ADC_EstructuraConfiguraciondelCanal;

/********************* FUNCIONES/CÓDIGO ******************** */
/*!
 * @brief Main function
 */
void ADCinit_ADCconfig(void){
	ADC_EstructuraConfiguracion.referenceVoltageSource = kADC16_ReferenceVoltageSourceVref;
    ADC_EstructuraConfiguracion.clockSource = kADC16_ClockSourceAsynchronousClock;
    ADC_EstructuraConfiguracion.enableAsynchronousClock = true;
    ADC_EstructuraConfiguracion.clockDivider = kADC16_ClockDivider8;
    ADC_EstructuraConfiguracion.resolution = kADC16_Resolution16Bit;
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
