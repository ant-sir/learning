/*
 * OperationAdd.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATIONADD_H_
#define OPERATIONADD_H_

#include "Operation.h"

class OperationAdd: public Operation
{
public:
	OperationAdd();
	virtual ~OperationAdd();
public:
	virtual double GetResult();
};

#endif /* OPERATIONADD_H_ */
