/**
 * Copyright @ 2014 - 2017 Suntec Software(Shanghai) Co., Ltd.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are NOT permitted except as agreed by
 * Suntec Software(Shanghai) Co., Ltd.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include "EngineTestDef.h"
#include "CL_WaitObj.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <FifoFile.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <limits.h>
#include <sys/ioctl.h>

FifoFile::FifoFile()
: strPipeName()
, nfdRead(0)
, nfdWrite(0)
{
	pid_t pid = gettid();
	std::stringstream s1;
	s1 << "/tmp/fifo" << pid;
    strPipeName = s1.str();
}

FifoFile::~FifoFile()
{
    ClosePipe();
}

bool FifoFile::CreatePipe()
{
    VC_LOG("VC_PipeCom::CreatePipe()");

    if (mkfifo(strPipeName.c_str(),0666) < 0) { // c_str()
    	VC_LOG("mkfifo error.");
        return false;
    }
    VC_LOG("Create pipe success");

    return true;
}
bool FifoFile::OpenForRead()
{
	if ((nfdRead = open(strPipeName.c_str(),O_RDONLY)) < 0) {
		VC_LOG("mkfifo open for write error.");
		ClosePipe();
		return false;
	}
	VC_LOG("Open PIPO for Read success.");
	return true;
}
bool FifoFile::OpenForWrite()
{
	if ((nfdWrite = open(strPipeName.c_str(), O_WRONLY)) < 0) { // waitfo pipe open
		ClosePipe();
		VC_LOG("open pipe file fail,please try anthor time");
		return false;
	}
	VC_LOG("Open PIPO for Write success.");
	return true;
}

int FifoFile::ReadPipe(void *buf,int len)
{
    int nlen = -1;
    nlen = read(nfdRead,buf,len);
	VC_LOG("Engine Read form PIPO [%d] BYTE.", nlen);
	return nlen;
}

bool FifoFile::WritePipe(const void *buf,int len)
{
	while(CheckDataAvailable())
		usleep(1000);
	write(nfdWrite,buf,len);
	VC_LOG("AudioIn Write to PIPO [%d] BYTE.", len);
    return true;
}

bool FifoFile::ClosePipe()
{
    if (0 == nfdRead) {
        VC_LOG("0 == nfdRead");
    }
    else {
        close(nfdRead); //关闭管道
    }

    if (0 == nfdWrite) {
        VC_LOG("0 == nfdWrite");
    }
    else {
        close(nfdWrite); //关闭管道
    }

    VC_LOG("Close pipe success:");
    return true;
}


bool FifoFile::CheckDataAvailable()
{
	int n = 0;
	ioctl(nfdRead, FIONREAD, &n);
	return n > 0 ? true : false;
}

void FifoFile::ClearPipe()
{
	unsigned char buf[4096];
	while(CheckDataAvailable())
		read(nfdRead, buf, sizeof(buf));
}
/* EOF */
