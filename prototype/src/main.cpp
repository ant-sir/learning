/*
 * main.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include "Prototype.h"
#include "ConcretePrototypeA.h"

int main()
{
	Prototype* pptt = new ConcretePrototypeA();
	pptt->m_strname = "第一份";
	pptt->show();
	Prototype* pptt2 = pptt->Clone();
	//pptt2->m_strname = "第二份";
	pptt2->show();
	return 0;
}
