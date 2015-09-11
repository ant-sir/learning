/*
 * BigTrouser.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include <iostream>
#include "BigTrouser.h"

BigTrouser::BigTrouser()
{
	// TODO Auto-generated constructor stub

}

BigTrouser::~BigTrouser()
{
	// TODO Auto-generated destructor stub
}

void BigTrouser::Show()
{
	FineryDecorator::Show();
	std::cout << "大裤衩 ";
}
