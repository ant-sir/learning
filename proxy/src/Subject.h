/*
 * Subject.h
 *
 *  Created on: 2015年7月15日
 *      Author: zyl
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject
{
public:
	Subject();
	virtual ~Subject();
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;
};

#endif /* SUBJECT_H_ */
