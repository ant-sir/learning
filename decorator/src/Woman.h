/*
 * Woman.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef WOMAN_H_
#define WOMAN_H_

#include "Human.h"

class Woman: public Human
{
public:
	Woman();
	virtual ~Woman();
public:
	virtual void Show();
};

#endif /* WOMAN_H_ */
