/*
 * Man.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef MAN_H_
#define MAN_H_

#include "Human.h"

class Man: public Human
{
public:
	Man();
	virtual ~Man();
public:
	virtual void Show();
};

#endif /* MAN_H_ */
