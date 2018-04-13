/*
 * PWMinit.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Manuel
 */

#ifndef PWMINIT_H_
#define PWMINIT_H_

#include "source/stdtypedef.h"

/********************* GENERAL FUNCTIONS ******************** */
extern void PWMinit_PWMtestRoutine(void);
extern void PWMinit_PWMset(void);

/********************* TEMPERATURE DECREASE ACTIONS ******************** */
extern void PWMinit_PWMnormalDecrease();
extern void PWMinit_PWMhighDecrease();

/********************* TEMPERATURE INCREASE ACTIONS ******************** */
extern void PWMinit_PWMnormalIncrease();
extern void PWMinit_PWMhighIncrease();

#endif /* PWMINIT_H_ */
