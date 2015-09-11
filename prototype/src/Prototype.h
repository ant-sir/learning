/*
 * Prototype.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <string>

class Prototype
{
public:
	Prototype();
	Prototype(const Prototype&);
	virtual ~Prototype();
public:
	virtual Prototype* Clone() = 0;
	virtual void show();
public:
	std::string m_strname;
};

#endif /* PROTOTYPE_H_ */
