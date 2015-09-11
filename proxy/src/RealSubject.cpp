/*
 * RealSubject.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include <iostream>
#include "RealSubject.h"

RealSubject::RealSubject()
{
	// TODO Auto-generated constructor stub

}

RealSubject::~RealSubject()
{
	// TODO Auto-generated destructor stub
}

void RealSubject::giveDolls()
{
	std::cout << "送洋娃娃" << std::endl;
}

void RealSubject::giveFlowers()
{
	std::cout << "送花" << std::endl;
}

void RealSubject::giveChocolate()
{
	std::cout << "送巧克力" << std::endl;
}
