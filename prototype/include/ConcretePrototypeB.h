/*
 * ConcretePrototypeB.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef CONCRETEPROTOTYPEB_H_
#define CONCRETEPROTOTYPEB_H_

#include "Prototype.h"

class ConcretePrototypeB: public Prototype
{
public:
	ConcretePrototypeB();
	virtual ~ConcretePrototypeB();
public:
	virtual Prototype* Clone();
};

#endif /* CONCRETEPROTOTYPEB_H_ */
