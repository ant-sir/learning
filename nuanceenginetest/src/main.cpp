/*
 * main.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: zyl
 */

#include <stdio.h>
#include <dlfcn.h>
#include "cmdline.h"
#include "pugixml.hpp"
#include "EngineTest.h"

int main(int argc, char* argv[])
{
	cmdline::parser cmdp;
	cmdp.add<std::string>("inputfile", 'i', "input xml file for test case", true, "");
	//cmdp.add<int>("testtype", 't', "input test type.", true, 1);
	cmdp.parse_check(argc, argv);
	std::cout << cmdp.get<std::string>("inputfile") << std::endl;

	EngineTest Test;
	Test.Initialize(cmdp.get<std::string>("inputfile"));
	Test.TestRecognize(EngineTest::RECOGNIZE);
/*
	Test.Update("/udisk/1000.txt", "song", false, true);
	Test.Update("/udisk/10.txt", "song", true, false);
	Test.Update("/udisk/10.txt", "song", false, false);
	Test.Update("/udisk/50.txt", "song", true, false);
	Test.Update("/udisk/50.txt", "song", false, false);
	
	Test.Update("/udisk/5000.txt", "song", false, true);
	Test.Update("/udisk/10.txt", "song", true, false);
	Test.Update("/udisk/10.txt", "song", false, false);
	Test.Update("/udisk/50.txt", "song", true, false);
	Test.Update("/udisk/50.txt", "song", false, false);
	
	Test.Update("/udisk/10000.txt", "song", false, true);
	Test.Update("/udisk/10.txt", "song", true, false);
	Test.Update("/udisk/10.txt", "song", false, false);
	Test.Update("/udisk/50.txt", "song", true, false);
	Test.Update("/udisk/50.txt", "song", false, false);
*/
	sleep(5);

	return 0;
}
