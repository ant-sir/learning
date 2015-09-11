/*
 * ConcretePrototypeA.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include "ConcretePrototypeA.h"
#include <iostream>

ConcretePrototypeA::ConcretePrototypeA()
{
	// TODO Auto-generated constructor stub

}

ConcretePrototypeA::~ConcretePrototypeA()
{
	// TODO Auto-generated destructor stub
}

Prototype* ConcretePrototypeA::Clone()
{
	return new ConcretePrototypeA(*this);
}



