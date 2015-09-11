/*
 * FineryDecorator.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef FINERYDECORATOR_H_
#define FINERYDECORATOR_H_

#include "Human.h"

class FineryDecorator: public Human
{
public:
	FineryDecorator();
	virtual ~FineryDecorator();
public:
	virtual void Decorate(Human* human);
	virtual void Show();
private:
	Human* m_human;
};

#endif /* FINERYDECORATOR_H_ */
