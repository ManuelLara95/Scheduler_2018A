/*
 * ADC_init.h
 *
 *  Created on: Apr 10, 2018
 *      Author: Manuel
 */

#ifndef ADCINIT_H_
#define ADCINIT_H_

extern T_UWORD ADCinit_getADCvalue(ADC_Type *base, uint32_t channelGroup);
extern void ADCinit_ADCconfig(void);

#endif /* ADCINIT_H_ */
