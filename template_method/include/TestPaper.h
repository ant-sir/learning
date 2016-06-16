/*
 * TestPaper.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef TESTPAPER_H_
#define TESTPAPER_H_

#include <string>

class TestPaper
{
public:
	TestPaper();
	virtual ~TestPaper();
public:
	void TestQuestion1();
	void TestQuestion2();
	void TestQuestion3();
	virtual std::string Answer1() = 0;
	virtual std::string Answer2() = 0;
	virtual std::string Answer3() = 0;
};

#endif /* TESTPAPER_H_ */
