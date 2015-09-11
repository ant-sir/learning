/*
 * ConcretePrototypeA.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef CONCRETEPROTOTYPEA_H_
#define CONCRETEPROTOTYPEA_H_

#include "Prototype.h"

class ConcretePrototypeA: public Prototype
{
public:
	ConcretePrototypeA();
	virtual ~ConcretePrototypeA();
public:
	virtual Prototype* Clone();
};

#endif /* CONCRETEPROTOTYPEA_H_ */
