/*
 * EngineTestDef.h
 *
 *  Created on: 2015年5月22日
 *      Author: zyl
 */

#ifndef ENGINETESTDEF_H_
#define ENGINETESTDEF_H_
#include <string>
#include <iostream>
#include <stdio.h>
#include "CL_NewTypesDefine.h"

class CLog
{
public:
	explicit CLog(const std::string & log)
	{
		logmsg = log;
		std::cout << logmsg << "[Enter]" << std::endl;
	};
	~CLog()
	{
		std::cout << logmsg << "[Exit]" << std::endl;
	};
	std::string logmsg;
};
#define DEBUG
#ifdef DEBUG
#define VC_ERROR(...)                       printf(__VA_ARGS__);\
                                            printf("\n")
#define VC_LOG(...)                         printf(__VA_ARGS__);\
                                            printf("\n")
#define VC_LOGD(...)                        printf(__VA_ARGS__);\
                                            printf("\n")

#define LOG_FUNCTION()	\
	CLog clog(__FUNCTION__)
#define LOG_ERROR(...)	\
	printf("[%s]:[%d]:%s\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define VC_ERROR(...)
#define VC_LOG(...)
#define VC_LOGD(...)
#define LOG_FUNCTION()
#define LOG_ERROR(...)
#endif
#endif /* ENGINETESTDEF_H_ */
