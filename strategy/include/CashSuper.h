/*
 * CashSuper.h
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#ifndef CASHSUPER_H_
#define CASHSUPER_H_

class CashSuper
{
public:
	CashSuper();
	virtual ~CashSuper();
public:
	virtual double acceptCash() = 0;
};

#endif /* CASHSUPER_H_ */
