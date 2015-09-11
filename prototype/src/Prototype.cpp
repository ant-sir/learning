/*
 * Prototype.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include <iostream>
#include "Prototype.h"

Prototype::Prototype()
: m_strname("")
{
	// TODO Auto-generated constructor stub

}

Prototype::~Prototype()
{
	// TODO Auto-generated destructor stub
}

void Prototype::show()
{
	std::cout << m_strname << std::endl;
}

Prototype::Prototype(const Prototype& ptt)
{
	m_strname = ptt.m_strname;
}
