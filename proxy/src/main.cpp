/*
 * main.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */
#include "Subject.h"
#include "RealSubject.h"
#include "Proxy.h"


int main()
{
	Subject* proxy = new Proxy();
	proxy->giveChocolate();
	proxy->giveDolls();
	proxy->giveFlowers();

	return 0;
}
