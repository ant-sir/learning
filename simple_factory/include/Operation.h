/*
 * Operation.h
 *
 *  Created on: 2015年7月13日
 *      Author: zyl
 */

#ifndef OPERATION_H_
#define OPERATION_H_

class Operation
{
public:
	Operation();
	virtual ~Operation();
public:
	virtual double GetResult() = 0;
public:
	double m_num1;
	double m_num2;
};

#endif /* OPERATION_H_ */
