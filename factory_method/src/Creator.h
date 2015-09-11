/*
 * Creator.h
 *
 *  Created on: 2015年7月16日
 *      Author: zyl
 */

#ifndef CREATOR_H_
#define CREATOR_H_
#include <string>

class Operation;

class Creator
{
public:
	Creator();
	virtual ~Creator();
public:
	virtual Operation* FactoryMethod() = 0;
	void OtherMethod(double, double);
};

#endif /* CREATOR_H_ */
