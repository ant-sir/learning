/*
 * C_IAudio_In.h
 *
 *  Created on: 2015年5月26日
 *      Author: zyl
 */

#ifndef C_IAUDIO_IN_H_
#define C_IAUDIO_IN_H_
#include <FifoFile.h>
#include "Vr_Asr_Audio_In.h"
#include <vector>
#include <string>
#include "WaveFile.h"
#include "BL_Thread.h"

class C_IAudio_In :public N_Vr::N_Asr::C_Audio_In, public BL_Thread
{
public:
	virtual int M_Fn_Start();
	virtual int M_Fn_Stop();
	virtual int M_Fn_Data_Available_Check(bool * pb_Data_Available);
	virtual int M_Fn_Data_Fetch(void ** ppvoid_Buffer, size_t * pi_Size);
	virtual int M_Fn_Data_Return(void * const & rpvoid_Buffer);

	virtual void Run();

	void SetWaveEOSTime();
	long GetWaveEOSTime();
public:
	explicit C_IAudio_In();
	virtual ~C_IAudio_In();

	void SendWaveFileEos(int sWaveFileEos)
	{
		m_sWaveFileEOS = sWaveFileEos;
	}

	void SendWaveFileName(const std::string &name)
	{
		m_sWaveFileName = name;
	}
	void SendTagID(const std::string & tagid)
	{
		m_sExpectResult = tagid;
	}
	std::string & GetTagid()
	{
		return m_sExpectResult;
	}
private:
	void DoTask();
	long GetSysTime();

private:
	enum
	{
		BUF_COUNT = 4,
		BUF_SIZE = 4096,
		RATE = 16000,
	};
	WaveFile m_WaveFile;
	std::string m_sWaveFileName;
	int m_sWaveFileEOS;
	std::vector<unsigned char> m_bBuffer;
	unsigned long m_nWaveEOSByte;
	volatile unsigned long m_nWaveFileLen;
	FifoFile m_AudioPipe;
	bool m_bEngineStop;
	long m_lEOSTime;
	std::string m_sExpectResult;
};

#endif /* C_IAUDIO_IN_H_ */
