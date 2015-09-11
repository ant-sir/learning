/*
 * CashReturn.h
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#ifndef CASHRETURN_H_
#define CASHRETURN_H_

#include "CashSuper.h"

class CashReturn: public CashSuper
{
public:
	CashReturn();
	virtual ~CashReturn();
public:
	virtual double acceptCash();
};

#endif /* CASHRETURN_H_ */
