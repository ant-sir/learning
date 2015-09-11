/*
 * ConcretePrototypeB.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include "ConcretePrototypeB.h"

ConcretePrototypeB::ConcretePrototypeB()
{
	// TODO Auto-generated constructor stub

}


ConcretePrototypeB::~ConcretePrototypeB()
{
	// TODO Auto-generated destructor stub
}

Prototype* ConcretePrototypeB::Clone()
{
	return new ConcretePrototypeB(*this);
}
