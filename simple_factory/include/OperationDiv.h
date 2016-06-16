/*
 * OperationDiv.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATIONDIV_H_
#define OPERATIONDIV_H_

#include "Operation.h"

class OperationDiv: public Operation
{
public:
	OperationDiv();
	virtual ~OperationDiv();
public:
	virtual double GetResult();
};

#endif /* OPERATIONDIV_H_ */
