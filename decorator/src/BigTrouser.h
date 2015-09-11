/*
 * BigTrouser.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef BIGTROUSER_H_
#define BIGTROUSER_H_

#include "FineryDecorator.h"

class Human;

class BigTrouser: public FineryDecorator
{
public:
	BigTrouser();
	virtual ~BigTrouser();
public:
	virtual void Show();
};

#endif /* BIGTROUSER_H_ */
