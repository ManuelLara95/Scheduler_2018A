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
void periodic_tasks_exec_500tks(void) {

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
	T_UWORD ADC_Value = ADCinit_getADCvalue(ADC0, CANAL0);
//	PRINTF("%dd\n", ADC_Value);
}
