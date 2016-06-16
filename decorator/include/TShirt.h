/*
 * TShirt.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef TSHIRT_H_
#define TSHIRT_H_

#include "FineryDecorator.h"

class Human;

class TShirt: public FineryDecorator
{
public:
	TShirt();
	virtual ~TShirt();
public:
	virtual void Show();
};

#endif /* TSHIRT_H_ */
