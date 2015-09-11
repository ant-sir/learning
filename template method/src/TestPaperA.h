/*
 * TestPaperA.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef TESTPAPERA_H_
#define TESTPAPERA_H_

#include "TestPaper.h"

class TestPaperA: public TestPaper
{
public:
	TestPaperA();
	virtual ~TestPaperA();
public:
	virtual std::string Answer1();
	virtual std::string Answer2();
	virtual std::string Answer3();
};

#endif /* TESTPAPERA_H_ */
