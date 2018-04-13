/*
 * PWMinit.c

 *
 *  Created on: Apr 12, 2018
 *      Author: Manuel
 */
/********************* INCLUSIONES ******************** */
#include "drivers_HAL/fsl_tpm.h"
#include "source/stdtypedef.h"
#include "pin_mux.h"
#include "PWMinit.h"
#include "board.h"

/********************* DEFINICIONES ******************** */
/* Interrupt to enable and flag to read; depends on the TPM channel used */
#define TPM_DIRECCIONBASE 		TPM2
#define TPM_NUMEROdeCANAL0 		0u
#define TPM_NUMEROdeCANAL1		1u

#define HALFofPOWER		50u
#define	FULLPOWER		100u
/* Get source clock for TPM driver */
#define TPM_CLOCKPRINCIPAL 		CLOCK_GetFreq(kCLOCK_PllFllSelClk)

/********************* VARIABLES ******************** */
volatile T_UBYTE updatedDutycycle = 1;
volatile T_UBYTE getCharValue = 0U;
T_BOOLEAN subiendo = TRUE;

/********************* CÓDIGO ******************** */
/*!
 * @brief PWMinit_PWMconfig configures PWM channel on default values
 */
void PWMinit_PWMconfig(void){
    tpm_config_t TPM_info;
    tpm_chnl_pwm_signal_param_t TPM_PARAMETRO[2];

    /* Configure tpm params with frequency 24kHZ */
    TPM_PARAMETRO[0].chnlNumber = (tpm_chnl_t)TPM_NUMEROdeCANAL0;
    TPM_PARAMETRO[0].level = kTPM_LowTrue;
    TPM_PARAMETRO[0].dutyCyclePercent = updatedDutycycle;

    TPM_PARAMETRO[1].chnlNumber = (tpm_chnl_t)TPM_NUMEROdeCANAL1;
	TPM_PARAMETRO[1].level = kTPM_LowTrue;
	TPM_PARAMETRO[1].dutyCyclePercent = updatedDutycycle;

    CLOCK_SetTpmClock(1u);				/* Select the clock source for the TPM counter as kCLOCK_PllFllSelClk */
    TPM_GetDefaultConfig(&TPM_info);

    /* Initialize TPM module */
    TPM_Init(TPM_DIRECCIONBASE, &TPM_info);

    TPM_SetupPwm(TPM_DIRECCIONBASE, TPM_PARAMETRO, 2U, kTPM_EdgeAlignedPwm, 24000U, TPM_CLOCKPRINCIPAL);
    TPM_StartTimer(TPM_DIRECCIONBASE, kTPM_SystemClock);
}

/*!
 * @brief PWMinit_PWMset sets a value onto a PWM channel
 */
void PWMinit_PWMtestRoutine(void){
	if(subiendo)
		updatedDutycycle += 1;
	else
		updatedDutycycle -= 1;

	if(updatedDutycycle == 100)
		subiendo = false;
	else if(updatedDutycycle == 0)
		subiendo = true;
	else;

	TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL1, kTPM_CenterAlignedPwm,
	                           updatedDutycycle);
}

void PWMinit_PWMnormalDecrease(){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL0, kTPM_CenterAlignedPwm,
    						HALFofPOWER);
}

void PWMinit_PWMhighDecrease(){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL0, kTPM_CenterAlignedPwm,
    						FULLPOWER);
}

void PWMinit_PWMnormalIncrease(){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL1, kTPM_CenterAlignedPwm,
    						HALFofPOWER);
}

void PWMinit_PWMhighIncrease(){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL1, kTPM_CenterAlignedPwm,
    						FULLPOWER);
}
