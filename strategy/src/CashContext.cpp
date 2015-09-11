/*
 * CashContext.cpp
 *
 *  Created on: 2015年7月14日
 *      Author: zyl
 */

#include "CashContext.h"
#include "CashSuper.h"

CashContext::CashContext(CashSuper& cs)
: m_pcs(cs)
{
	// TODO Auto-generated constructor stub

}

CashContext::~CashContext()
{
	// TODO Auto-generated destructor stub
}

double CashContext::GetResult()
{
	return m_pcs.acceptCash();
}
