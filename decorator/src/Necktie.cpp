/*
 * Necktie.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include <iostream>
#include "Necktie.h"

Necktie::Necktie()
{
	// TODO Auto-generated constructor stub

}

Necktie::~Necktie()
{
	// TODO Auto-generated destructor stub
}

void Necktie::Show()
{
	FineryDecorator::Show();
	std::cout << "领带 ";
}
