/*
 * OperationFactory.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATIONFACTORY_H_
#define OPERATIONFACTORY_H_

#include <string>
#include "Operation.h"

class OperationFactory
{
public:
	OperationFactory();
	virtual ~OperationFactory();
public:
	static Operation* createOpearte(char chr);
};

#endif /* OPERATIONFACTORY_H_ */
