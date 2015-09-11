/*
 * main.cpp
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#include "Creator.h"
#include "SubFactory.h"


int main()
{
	Creator* pcreator = new SubFactory();
	pcreator->OtherMethod(3, 5);
	pcreator->OtherMethod(10, 5);
	return 0;
}
