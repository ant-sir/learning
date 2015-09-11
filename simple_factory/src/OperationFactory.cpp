/*
 * OperationFactory.cpp
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#include "OperationFactory.h"
#include "OperationAdd.h"
#include "OperationSub.h"
#include "OperationMul.h"
#include "OperationDiv.h"

OperationFactory::OperationFactory()
{
	// TODO Auto-generated constructor stub

}

OperationFactory::~OperationFactory()
{
	// TODO Auto-generated destructor stub
}

Operation* OperationFactory::createOpearte(char chr)
{
	Operation* pOperate = nullptr;
	switch( chr )
	{
	case '+':
		pOperate = new OperationAdd();break;
	case '-':
		pOperate = new OperationSub();break;
	case '*':
		pOperate = new OperationMul();break;
	case '/':
		pOperate = new OperationDiv();break;
	default:
		pOperate = nullptr;
	}
	return pOperate;
}
