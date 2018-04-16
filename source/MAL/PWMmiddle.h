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
#define TOLERANCIAincrementoNORMAL		62		// +5°
#define TOLERANCIAincrementoRAPIDO		124		// +10°

#define TOLERANCIAdecrementoNORMAL		62		// -5°
#define TOLERANCIAdecrementoRAPIDO		124		// -10°
#define VALORDETEMPERATURAbase			335		// A 27°

#define MAXsafeLimit		VALORDETEMPERATURAbase + TOLERANCIAincrementoNORMAL
#define highDANGERLimit		VALORDETEMPERATURAbase + TOLERANCIAincrementoRAPIDO
#define MINsafeLimit		VALORDETEMPERATURAbase - TOLERANCIAdecrementoNORMAL
#define lowDANGERlimit		VALORDETEMPERATURAbase - TOLERANCIAdecrementoRAPIDO

/********************* PROTOTIPOS ******************** */
extern T_UBYTE PWMmiddle_setOperationMODE(T_UWORD ADC_VALUE);

#endif /* MAL_PWMMIDDLE_H_ */
