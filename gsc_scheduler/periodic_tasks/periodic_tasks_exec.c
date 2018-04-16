/*============================================================================*/
/*                     AZOR - EMBEDDED SYSTEMS SOFTWARE                       */
/*============================================================================
* C Source:        periodic_tasks_exec.c
* version:         1.0 
* created_by:      MDRR
* date_created:    July 31 2013 */

/********************* INCLUSIONES ******************** */
#include <gsc_scheduler/periodic_tasks/periodic_tasks_exec.h>
#include <gsc_scheduler/periodic_tasks/periodic_tasks_modules.h>

/********************* DEFINICIONES ******************** */
T_UWORD ADC_Value = 0;
T_UBYTE DANGER_counter = 0;
bool DANGER_flag = false;
enum ModoDeOperacion MODOactual;
#define	CANAL0	0U

/**************************************************************
*  Name                 : periodic_tasks_exec_5tks
*	ID					 : TASK_5TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_5tks(void){

}

/**************************************************************
*  Name                 : periodic_tasks_exec_10tks
*	ID					 : TASK_10TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_10tks(void){
	ADC_Value = ADCinit_getADCvalue(ADC0, CHNL0);
}

/**************************************************************
*  Name                 : periodic_tasks_exec_20tks
*	ID					 : TASK_20TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_20tks(void){
	PWMinit_PWMtestRoutine();
}

/**************************************************************
*  Name                 : periodic_tasks_exec_50tks
*	ID					 : TASK_50TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_50tks(void){
//	PWMinit_PWMnormalDecrease();
//	DELAY_delay(40);
}

/**************************************************************
*  Name                 : periodic_tasks_exec_100tks
*	ID					 : TASK_100TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_100tks(void){
//	PWMinit_PWMhighDecrease();
//	DELAY_delay(40);
}

/**************************************************************
*  Name                 : periodic_tasks_exec_500tks
*	ID					 : TASK_500TKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_500tks(void){
	MODOactual = PWMmiddle_setOperationMODE(ADC_Value);
}

/**************************************************************
*  Name                 : periodic_tasks_exec_1Mtks
*	ID					 : TASK_1MTKS
*  Description          : Container for functionality that is
					   executed periodically.
*  Parameters           : none
*  Return               : none
*  Critical/explanation : no
**************************************************************/
void periodic_tasks_exec_1Mtks(void){
	ADC_Value = ((3300*ADC_Value*100)/4095);
	PRINTF("%dd\n", ADC_Value);
	PRINTF("%dd\n", MODOactual);

	if(MODOactual == DECREMENTO_RAPIDO || MODOactual == INCREMENTO_RAPIDO)
		{
			DANGER_counter++;
			if(DANGER_counter >= 30u)
				MODOactual = MODO_SEGURO;
		}
	else
		DANGER_counter = 0;
//	PRINTF("%dd\n", ADC_Value);
}
