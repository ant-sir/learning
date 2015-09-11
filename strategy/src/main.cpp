/*
 * main.cpp
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#include "CashContext.h"
#include "CashSuper.h"
#include "CashNormal.h"
#include "CashRebate.h"

int main()
{
	CashContext* pcc = new CashContext(*(new CashRebate()));
	pcc->GetResult();

	pcc = new CashContext(*(new CashNormal()));
	pcc->GetResult();
	return 0;
}
