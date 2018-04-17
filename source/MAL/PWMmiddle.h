/*
 * PWMmiddle.h
 *
 *  Created on: Apr 15, 2018
 *      Author: Manuel
 */
#ifndef MAL_PWMMIDDLE_H_
#define MAL_PWMMIDDLE_H_

/********************* INCLUSIONES ******************** */
#include "source/HAL/ADCconfig.h"
#include "source/HAL/PWMconfig.h"

/********************* DEFINICIONES ******************** */
#define TOLERANCIAincrementoNORMAL		10		// +10°
#define TOLERANCIAincrementoRAPIDO		20		// +50°

#define TOLERANCIAdecrementoNORMAL		3		// -3°
#define TOLERANCIAdecrementoRAPIDO		5		// -5°
#define VALORDETEMPERATURAbase			26

#define MAXsafeLimit		VALORDETEMPERATURAbase + TOLERANCIAincrementoNORMAL
#define highDANGERLimit		VALORDETEMPERATURAbase + TOLERANCIAincrementoRAPIDO
#define MINsafeLimit		VALORDETEMPERATURAbase - TOLERANCIAdecrementoNORMAL
#define lowDANGERlimit		VALORDETEMPERATURAbase - TOLERANCIAdecrementoRAPIDO

/********************* DECLARACIONES ******************** */
enum ModoDeOperacion{
	MODO_NORMAL,
	INCREMENTO_NORMAL,
	INCREMENTO_RAPIDO,
	DECREMENTO_NORMAL,
	DECREMENTO_RAPIDO,
	MODO_SEGURO
};
/********************* PROTOTIPOS ******************** */
extern T_UBYTE PWMmiddle_setOperationMODE(T_UWORD ADC_VALUE);

#endif /* MAL_PWMMIDDLE_H_ */
