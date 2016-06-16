/*
 * OperationMul.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATIONMUL_H_
#define OPERATIONMUL_H_

#include "Operation.h"

class OperationMul: public Operation
{
public:
	OperationMul();
	virtual ~OperationMul();
public:
	virtual double GetResult();
};

#endif /* OPERATIONMUL_H_ */
