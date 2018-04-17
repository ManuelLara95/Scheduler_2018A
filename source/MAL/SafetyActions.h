/*
 * SafetyActions.h
 *
 *  Created on: Apr 15, 2018
 *      Author: Manuel
 */

#ifndef MAL_SAFETYACTIONS_H_
#define MAL_SAFETYACTIONS_H_

/********************* INCLUSIONES ******************** */
#include "source/stdtypedef.h"
#include "MAL/PWMmiddle.h"
#include "MAL/ADCmiddle.h"
#include <drivers_HAL/fsl_common.h>
#include <drivers_HAL/fsl_port.h>
#include "pin_mux.h"

/********************* PROTOTIPOS ******************** */
extern bool SafetyActions_SafetyChecker(T_UBYTE MODOactual);
extern T_UBYTE SafetyActions_SafetyCounter(T_UBYTE ActualMODE);
extern bool SafetyActions_SafetyConfig(void);
extern void SafetyActions_SetPinsasInputs(void);
extern void SafetyActions_SetPinsasOutputs(void);
extern bool SafetyActions_DangerChecker(T_UBYTE lul_MODOactual);

#endif /* MAL_SAFETYACTIONS_H_ */
