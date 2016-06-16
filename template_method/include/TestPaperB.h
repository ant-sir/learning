/*
 * TestPaperB.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef TESTPAPERB_H_
#define TESTPAPERB_H_

#include "TestPaper.h"

class TestPaperB: public TestPaper
{
public:
	TestPaperB();
	virtual ~TestPaperB();
public:
	virtual std::string Answer1();
	virtual std::string Answer2();
	virtual std::string Answer3();
};

#endif /* TESTPAPERB_H_ */
