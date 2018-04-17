/*
 * SafetyActions.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Manuel
 */

/********************* INCLUSIONES ******************** */
#include "SafetyActions.h"

/********************* DECLARACIONES ******************** */
T_UBYTE Safety_Counter = 0;
T_UWORD ADCValue = 0;
T_UBYTE MODE = 0, DCounter;
bool SAFEMODEflag = false, DANGER_detected = false;

bool SafetyActions_SafetyChecker(T_UBYTE DANGERcount){
	if(DANGERcount > 30)
		return true;
	else
		return false;
}

T_UBYTE SafetyActions_SafetyCounter(T_UBYTE ActualMODE){
	if(ActualMODE == DECREMENTO_RAPIDO || ActualMODE == INCREMENTO_RAPIDO)
		++Safety_Counter;
	else
		Safety_Counter = 0;

	return Safety_Counter;
}

bool SafetyActions_SafetyConfig(void){
	ADCValue = ADCmiddle_getTemperature();
	MODE = PWMmiddle_setOperationMODE(ADCValue);
	if(SafetyActions_DangerChecker(MODE))
	{
		SafetyActions_SetPinsasInputs();
		PRINTF("MODO SEGURO ACTIVO\n");
		SAFEMODEflag = true;;
	}

	else
	{
		SafetyActions_SetPinsasOutputs();
		PRINTF("MODO SEGURO DESACTIVADO\n");
		SAFEMODEflag = false;
	}
	return SAFEMODEflag;
}

void SafetyActions_SetPinsasInputs(void){
	  PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAsGpio);				/* PORTA1 (pin 27) is configured as GPIO */
	  PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAsGpio);				/* PORTA2 (pin 28) is configured as GPIO */
	  GPIOA->PDDR &= ~PIN1_IDX;
	  GPIOA->PDDR &= ~PIN2_IDX;

	  PORT_SetPinMux(PORTE, PIN22_IDX, kPORT_MuxAsGpio);			/* PORTE22 (pin 53) is configured as GPIO */
	  PORT_SetPinMux(PORTE, PIN23_IDX, kPORT_MuxAsGpio);			/* PORTE23 (pin 54) is configured as GPIO */
	  GPIOE->PDDR &= ~PIN22_IDX;
	  GPIOE->PDDR &= ~PIN23_IDX;
}

void SafetyActions_SetPinsasOutputs(void){
	GPIOA->PDDR |= PIN1_IDX;
	GPIOA->PDDR |= PIN2_IDX;
	PORT_SetPinMux(PORTA, PIN1_IDX, kPORT_MuxAlt2);				/* PORTA1 (pin 27) is configured as UART0_RX */
	PORT_SetPinMux(PORTA, PIN2_IDX, kPORT_MuxAlt2);				/* PORTA2 (pin 28) is configured as UART0_TX */

	GPIOE->PDDR |= PIN22_IDX;
	GPIOE->PDDR |= PIN23_IDX;
	PORT_SetPinMux(PORTE, PIN22_IDX, kPORT_MuxAlt3);				/* PORTE22 (pin 53) is configured as TPM2_CH0 */
	PORT_SetPinMux(PORTE, PIN23_IDX, kPORT_MuxAlt3);				/* PORTE23 (pin 54) is configured as TPM2_CH1 */
}

bool SafetyActions_DangerChecker(T_UBYTE lul_MODOactual){
	if(lul_MODOactual != MODO_NORMAL)
		return true;
	else return false;
}
