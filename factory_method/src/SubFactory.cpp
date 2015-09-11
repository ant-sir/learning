/*
 * SubFactory.cpp
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#include "SubFactory.h"
#include "OperationSub.h"

SubFactory::SubFactory()
{
	// TODO Auto-generated constructor stub

}

SubFactory::~SubFactory()
{
	// TODO Auto-generated destructor stub
}

Operation* SubFactory::FactoryMethod()
{
	return new OperationSub();
}
