/*
 * AddFactory.cpp
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#include "AddFactory.h"
#include "OperationAdd.h"

AddFactory::AddFactory()
{
	// TODO Auto-generated constructor stub

}

AddFactory::~AddFactory()
{
	// TODO Auto-generated destructor stub
}

Operation* AddFactory::FactoryMethod()
{
	return new OperationAdd();
}
