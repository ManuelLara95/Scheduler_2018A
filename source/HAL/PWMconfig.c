/*
 * PWMinit.c

 *
 *  Created on: Apr 12, 2018
 *      Author: Manuel
 */

#include <HAL/PWMconfig.h>

/********************* VARIABLES ******************** */
volatile T_UBYTE DutyCycle = 0;
T_BOOLEAN subiendo = TRUE;

/********************* CÓDIGO ******************** */
/*!
 * @brief PWMinit_PWMconfig configures PWM channel on default values
 */
void PWMinit_PWMsetconfig(void){
    tpm_config_t TPM_info;
    tpm_chnl_pwm_signal_param_t TPM_PARAMETRO[2];

    /* Configure tpm params with frequency 24kHZ */
    TPM_PARAMETRO[0].chnlNumber = (tpm_chnl_t)TPM_NUMEROdeCANAL0;
    TPM_PARAMETRO[0].level = kTPM_HighTrue;
    TPM_PARAMETRO[0].dutyCyclePercent = DutyCycle;

    TPM_PARAMETRO[1].chnlNumber = (tpm_chnl_t)TPM_NUMEROdeCANAL1;
	TPM_PARAMETRO[1].level = kTPM_HighTrue;
	TPM_PARAMETRO[1].dutyCyclePercent = DutyCycle;

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
		DutyCycle += 1;
	else
		DutyCycle -= 1;

	if(DutyCycle == 100)
		subiendo = false;
	else if(DutyCycle == 0)
		subiendo = true;
	else;

	TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMEROdeCANAL1, kTPM_CenterAlignedPwm,
	                           DutyCycle);
}

void PWMinit_PWM_setNORMALmode(tpm_chnl_t TPM_NUMERODECANAL){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMERODECANAL, kTPM_CenterAlignedPwm,
    						NOPOWER);
}

void PWMinit_PWM_NORMALCHANGE(tpm_chnl_t TPM_NUMERODECANAL){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMERODECANAL, kTPM_CenterAlignedPwm,
    						HALFofPOWER);
}

void PWMinit_PWM_DANGERCHANGE(tpm_chnl_t TPM_NUMERODECANAL){
    TPM_UpdatePwmDutycycle(TPM_DIRECCIONBASE, (tpm_chnl_t)TPM_NUMERODECANAL, kTPM_CenterAlignedPwm,
    						FULLPOWER);
}
