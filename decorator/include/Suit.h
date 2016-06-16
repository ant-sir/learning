/*
 * Suit.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef SUIT_H_
#define SUIT_H_

#include "FineryDecorator.h"

class Human;

class Suit: public FineryDecorator
{
public:
	Suit();
	virtual ~Suit();
public:
	virtual void Show();
};

#endif /* SUIT_H_ */
