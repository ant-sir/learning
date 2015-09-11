/*
 * OperationSub.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATIONSUB_H_
#define OPERATIONSUB_H_

#include "Operation.h"

class OperationSub: public Operation
{
public:
	OperationSub();
	virtual ~OperationSub();
public:
	virtual double GetResult();
};

#endif /* OPERATIONSUB_H_ */
