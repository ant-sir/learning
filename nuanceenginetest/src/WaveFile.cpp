/*
 * WaveFile.cpp
 *
 *  Created on: 2015年6月5日
 *      Author: zyl
 */

#include <WaveFile.h>
#include "EngineTestDef.h"
#include <sys/stat.h>
#include <fcntl.h>

WaveFile::WaveFile()
: CFile(O_RDONLY)
, m_iDataLen(0)
{
}

bool WaveFile::Open(const std::string& file_name)
{
	CFile::Open(file_name);
	if(!CheckWaveHead())
	{
		VC_ERROR("Check Wave Head Eoor.");
		return false;
	}
	return true;
}

bool WaveFile::CheckWaveHead()
{
	struct stat statbuff;
	if(fstat(m_file, &statbuff) < 0)
	{
		VC_ERROR("Get file state error: %s", strerror(errno));
		return false;
	}
	int file_len = statbuff.st_size;
	WAV_HDR hdr;
	memset(&hdr, 0, sizeof(hdr));
	if(read(m_file, &hdr, sizeof(hdr)) <= 0)
	{
		VC_ERROR("Read WAV_HDR error: %s", strerror(errno));
		return false;
	}
	if ((memcmp(&hdr.rID, "RIFF", 4) != 0)
		||  (memcmp(&hdr.wID, "WAVE", 4) != 0)
		||  (memcmp(&hdr.fId, "fmt ", 4) != 0))
	{
		VC_ERROR("WAV_HDR error.");
		return false;
	}
	CHUNK_HDR chdr;
	if(read(m_file, &chdr, sizeof(chdr)) <= 0)
	{
		VC_ERROR("Read CHUNK_HDR error: %s", strerror(errno));
		return false;
	}
	if ((memcmp(&chdr.dId, "data", 4) == 0)
		|| (memcmp(&chdr.dId, "fact", 4) == 0))
	{
		m_iDataLen = file_len - sizeof(chdr) - sizeof(hdr);
		return true;
	}
	VC_ERROR("CHUNK_HDR error.");
	return false;
}

int WaveFile::GetAvailableLen()
{
	return m_iDataLen;
}

WaveFile::~WaveFile()
{
}

