/*
 * Necktie.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef NECKTIE_H_
#define NECKTIE_H_

#include "FineryDecorator.h"
class Human;

class Necktie: public FineryDecorator
{
public:
	Necktie();
	virtual ~Necktie();
public:
	virtual void Show();
};

#endif /* NECKTIE_H_ */
