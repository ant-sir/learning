/*
 * Proxy.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef PROXY_H_
#define PROXY_H_

#include "Subject.h"

class Subject;

class Proxy: public Subject
{
public:
	Proxy();
	virtual ~Proxy();
public:
	virtual void giveDolls();
	virtual void giveFlowers();
	virtual void giveChocolate();
private:
	Subject* m_subject;
};

#endif /* PROXY_H_ */
