/*
 * CashContext.h
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#ifndef CASHCONTEXT_H_
#define CASHCONTEXT_H_
class CashSuper;

class CashContext
{
public:
	CashContext(CashSuper& cs);
	virtual ~CashContext();
public:
	double GetResult();
private:
	CashSuper& m_pcs;
};

#endif /* CASHCONTEXT_H_ */
