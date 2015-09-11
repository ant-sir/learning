/*
 * CashRebate.h
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#ifndef CASHREBATE_H_
#define CASHREBATE_H_

#include "CashSuper.h"

class CashRebate: public CashSuper
{
public:
	CashRebate();
	virtual ~CashRebate();
public:
	virtual double acceptCash();
};

#endif /* CASHREBATE_H_ */
