/*
 * CFile.cpp
 *
 *  Created on: 2015年6月4日
 *      Author: zyl
 */

#include <CFile.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "EngineTestDef.h"

CFile::CFile()
: m_file(0)
, m_mode(O_WRONLY | O_CREAT)
{
	// TODO Auto-generated constructor stub

}

CFile::CFile(int mode)
: m_file(0)
, m_mode(mode)
{
}
CFile::~CFile()
{
}

bool CFile::Open(const std::string & file_name)
{
	if(file_name.empty())
	{
		VC_ERROR("Open error, file name is empty.");
		return false;
	}
	if(-1 == (m_file = open(file_name.c_str(), m_mode)))
	{
		VC_ERROR("Open error: %s", strerror(errno));
		return false;
	}
	VC_LOG("Open [%s] success.", file_name.c_str());
	return true;
}

bool CFile::Close()
{
	if(!close(m_file))
		return true;
	VC_ERROR("Close file error: %s", strerror(errno));
	return false;
}

int CFile::Read(void* buf, int len)
{
	if(buf == NULL)
	{
		VC_ERROR("Read error: buffer is NULL");
		return -1;
	}
	int rlen = 0;
	if((rlen = read(m_file, buf, len)) == -1)
	{
		VC_ERROR("Read error: %s", strerror(errno));
		return -1;
	}
	VC_LOG("Read [%d] BYTES form file.", rlen);
	return rlen;
}

int CFile::Write(const void* buf, int len)
{
	if(buf == NULL)
	{
		VC_ERROR("Write error: buffer is NULL");
		return -1;
	}
	int rlen = 0;
	if((rlen = write(m_file, buf, len)) == -1)
	{
		VC_ERROR("Write error: %s", strerror(errno));
		return -1;
	}
	VC_LOG("Write to buffer [%d] BYTES.", rlen);
	return rlen;
}

