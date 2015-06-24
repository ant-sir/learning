/*
 * C_IAudio_In.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: zyl
 */

#include "C_IAudio_In.h"
#include "EngineTestDef.h"
#include <ctime>
#include <iostream>
C_IAudio_In::C_IAudio_In()
: m_WaveFile()
, m_sWaveFileName("")
, m_sWaveFileEOS(-1)
, m_bBuffer()
, m_nWaveEOSByte(-1)
, m_nWaveFileLen(0)
, m_AudioPipe()
, m_bEngineStop(false)
, m_lEOSTime(0)
, m_sExpectResult("")
{
	m_bBuffer.resize(4096);
	m_AudioPipe.CreatePipe();
	StartRegistThread();
	m_AudioPipe.OpenForWrite();
}

int C_IAudio_In::M_Fn_Start()
{
	LOG_FUNCTION();
	m_AudioPipe.ClearPipe();
	m_bEngineStop = false;
	m_lEOSTime = 0;
	Notify();
	return 0;
}

int C_IAudio_In::M_Fn_Stop()
{
	LOG_FUNCTION();
	if(m_lEOSTime == 0)
		SetWaveEOSTime();
	m_bEngineStop = true;
	return 0;
}

int C_IAudio_In::M_Fn_Data_Available_Check(bool* pb_Data_Available)
{
	LOG_FUNCTION();
	*pb_Data_Available = m_AudioPipe.CheckDataAvailable();
	return 0;
}

int C_IAudio_In::M_Fn_Data_Fetch(void** ppvoid_Buffer, size_t* pi_Size)
{
	LOG_FUNCTION();
	int r = m_AudioPipe.ReadPipe(m_bBuffer.data(), m_bBuffer.size());
	if(r == -1)
	{
		std::cout << "Read from PIPE error." << std::endl;
		return -1;
	}
	*ppvoid_Buffer = m_bBuffer.data();
	*pi_Size = r;
	std::cout << "Engine Fetch length = " << r << std::endl;
	return 0;
}

int C_IAudio_In::M_Fn_Data_Return(void* const & rpvoid_Buffer)
{
	LOG_FUNCTION();
	m_bBuffer.empty();
	return 0;
}

C_IAudio_In::~C_IAudio_In()
{
	m_AudioPipe.ClosePipe();
	StopThread();
}


void C_IAudio_In::Run()
{
	m_AudioPipe.OpenForRead();
	while(true)
	{
		Wait();
		if(CheckQuit()) break;
		DoTask();
	}
}

void C_IAudio_In::SetWaveEOSTime()
{
	m_lEOSTime = GetSysTime();
}

long C_IAudio_In::GetWaveEOSTime()
{
	return m_lEOSTime;
}

void C_IAudio_In::DoTask()
{
	m_WaveFile.Open(m_sWaveFileName);
	m_nWaveFileLen = m_WaveFile.GetAvailableLen();
	m_nWaveEOSByte = m_sWaveFileEOS*32 ? m_sWaveFileEOS*32 : m_nWaveFileLen;
	if(m_nWaveEOSByte > m_nWaveFileLen)
		return;
	VC_LOG("Wave file [%s] length: [%ld] BYTE.", m_sWaveFileName.c_str(), m_nWaveFileLen);
	VC_LOG("Wave file [%s] EOSLen: [%ld] BYTE.", m_sWaveFileName.c_str(), m_nWaveEOSByte);
	int nlen = 0;
	int rlen = 4096;
	unsigned long ntotal = 0;
	unsigned char buf[4096] = {0};
	if(m_nWaveEOSByte <= 4096)
	{
		nlen = m_WaveFile.Read(buf, m_nWaveEOSByte);
		m_AudioPipe.WritePipe(buf, nlen);
		ntotal += nlen;
		usleep(5000);
	}
	while((nlen = m_WaveFile.Read(buf, rlen)))
	{
		if(m_bEngineStop)break;
		VC_LOG("AudioIn has already been read [%ld] BYTE.", ntotal + nlen);
		m_AudioPipe.WritePipe(buf, nlen);
		ntotal += nlen;
		if(ntotal == m_nWaveEOSByte)
			SetWaveEOSTime();
		if(ntotal >= m_nWaveFileLen)break;//完了
		usleep(5000);
		if(ntotal < m_nWaveEOSByte && ntotal + 4096 > m_nWaveEOSByte)
		{
			rlen = m_nWaveEOSByte - ntotal;
			continue;
		}
		rlen = 4096;
	}
	m_WaveFile.Close();
}

long C_IAudio_In::GetSysTime()
{
	timespec tm;
	memset(&tm, 0, sizeof(tm));
	clock_gettime(CLOCK_MONOTONIC, &tm);
	return tm.tv_nsec;
}
