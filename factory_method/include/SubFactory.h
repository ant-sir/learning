/*
 * SubFactory.h
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#ifndef SUBFACTORY_H_
#define SUBFACTORY_H_

#include "Creator.h"

class SubFactory: public Creator
{
public:
	SubFactory();
	virtual ~SubFactory();
public:
	virtual Operation* FactoryMethod();
};

#endif /* SUBFACTORY_H_ */
