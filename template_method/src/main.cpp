/*
 * main.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include "TestPaper.h"
#include "TestPaperA.h"
#include "TestPaperB.h"

int main()
{
	TestPaper* ptpa = new TestPaperA();
	ptpa->TestQuestion1();
	ptpa->TestQuestion2();
	ptpa->TestQuestion3();

	TestPaper* ptpb = new TestPaperB();
	ptpb->TestQuestion1();
	ptpb->TestQuestion2();
	ptpb->TestQuestion3();
	return 0;
}
