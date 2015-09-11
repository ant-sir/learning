/*
 * AddFactory.h
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#ifndef ADDFACTORY_H_
#define ADDFACTORY_H_

#include "Creator.h"

class AddFactory: public Creator
{
public:
	AddFactory();
	virtual ~AddFactory();
public:
	virtual Operation* FactoryMethod();
};

#endif /* ADDFACTORY_H_ */
