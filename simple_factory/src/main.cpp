/*
 * main.cpp
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#include <iostream>
#include "Operation.h"
#include "OperationFactory.h"

int main()
{
	Operation* oper = nullptr;
	oper = OperationFactory::createOpearte('+');
	oper->m_num1 = 1;
	oper->m_num2 = 3;
	std::cout << oper->GetResult() << std::endl;
	return 0;
}
