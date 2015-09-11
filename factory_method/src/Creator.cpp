/*
 * Creator.cpp
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */
#include <iostream>
#include "Creator.h"
#include "Operation.h"

Creator::Creator()
{
	// TODO Auto-generated constructor stub

}

Creator::~Creator()
{
	// TODO Auto-generated destructor stub
}

void Creator::OtherMethod(double a, double b)
{
	Operation* pop = FactoryMethod();
	pop->m_num1 = a;
	pop->m_num2 = b;
	std::cout << "结果为：" << pop->GetResult() << std::endl;
}
