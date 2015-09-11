/*
 * Suit.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include <iostream>
#include "Suit.h"

Suit::Suit()
{
	// TODO Auto-generated constructor stub

}

Suit::~Suit()
{
	// TODO Auto-generated destructor stub
}

void Suit::Show()
{
	FineryDecorator::Show();
	std::cout << "西服 ";
}
