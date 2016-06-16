/*
 * CashNormal.h
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#ifndef CASHNORMAL_H_
#define CASHNORMAL_H_

#include "CashSuper.h"

class CashNormal: public CashSuper
{
public:
	CashNormal();
	virtual ~CashNormal();
public:
	virtual double acceptCash();
};

#endif /* CASHNORMAL_H_ */
