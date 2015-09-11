/*
 * RealSubject.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef REALSUBJECT_H_
#define REALSUBJECT_H_

#include "Subject.h"

class RealSubject: public Subject
{
public:
	RealSubject();
	virtual ~RealSubject();
public:
	virtual void giveDolls();
	virtual void giveFlowers();
	virtual void giveChocolate();
};

#endif /* REALSUBJECT_H_ */
