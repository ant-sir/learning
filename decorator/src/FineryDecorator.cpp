/*
 * FineryDecorator.cpp
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#include "FineryDecorator.h"

FineryDecorator::FineryDecorator()
: m_human(nullptr)
{
	// TODO Auto-generated constructor stub

}

FineryDecorator::~FineryDecorator()
{
	// TODO Auto-generated destructor stub
}

void FineryDecorator::Show()
{
	m_human->Show();
}

void FineryDecorator::Decorate(Human* human)
{
	m_human = human;
}
