/*
 * TShirt.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include <iostream>
#include "TShirt.h"

TShirt::TShirt()
{
	// TODO Auto-generated constructor stub

}

TShirt::~TShirt()
{
	// TODO Auto-generated destructor stub
}

void TShirt::Show()
{
	FineryDecorator::Show();
	std::cout << "T裇 ";
}
