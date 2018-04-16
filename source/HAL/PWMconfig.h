/*
 * PWMinit.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Manuel
 */

#ifndef PWMINIT_H_
#define PWMINIT_H_

/********************* INCLUSIONES ******************** */
#include "drivers_HAL/fsl_tpm.h"
#include "source/stdtypedef.h"
#include "pin_mux.h"
#include "board.h"

/********************* DEFINICIONES ******************** */
#define TPM_NUMEROdeCANAL0 		0u
#define TPM_NUMEROdeCANAL1		1u
#define TPM_DIRECCIONBASE 		TPM2

#define NOPOWER			0u
#define HALFofPOWER		25u
#define	FULLPOWER		100u
/* Get source clock for TPM driver */
#define TPM_CLOCKPRINCIPAL 		CLOCK_GetFreq(kCLOCK_PllFllSelClk)

/********************* PROTOTIPADO ******************** */
/********************* GENERAL FUNCTIONS ******************** */
extern void PWMinit_PWMsetconfig(void);
extern void PWMinit_PWMtestRoutine(void);
extern void PWMinit_PWMset(void);

/********************* TEMPERATURE CHANGE ACTIONS ******************** */
extern void PWMinit_PWM_setNORMALmode(tpm_chnl_t TPM_NUMERODECANAL);
extern void PWMinit_PWM_NORMALCHANGE(tpm_chnl_t TPM_NUMERODECANAL);
extern void PWMinit_PWM_DANGERCHANGE(tpm_chnl_t TPM_NUMERODECANAL);


#endif /* PWMINIT_H_ */
