/*
 * Proxy.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include "Proxy.h"
#include "RealSubject.h"

Proxy::Proxy()
: m_subject(nullptr)
{
	// TODO Auto-generated constructor stub
	if (m_subject == nullptr)
		m_subject = new RealSubject();
}

Proxy::~Proxy()
{
	// TODO Auto-generated destructor stub
}

void Proxy::giveDolls()
{
	m_subject->giveChocolate();
}

void Proxy::giveFlowers()
{
	m_subject->giveDolls();
}

void Proxy::giveChocolate()
{
	m_subject->giveFlowers();
}
