/*
 * WaveFile.h
 *
 *  Created on: 2015年6月5日
 *      Author: zyl
 */

#ifndef WAVEFILE_H_
#define WAVEFILE_H_

#include <CFile.h>

class WaveFile: public CFile
{
private:
	struct CHUNK_HDR
	{
	    char dId[4];            // 'data' or 'fact'
	    long int dLen;          // data length
	//  unsigned char data[0];
	};
	struct WAV_HDR
	{
	    char rID[4];                	// 'RIFF'
	    long rLen;              		// member description for rLen
	    char wID[4];               	 	// 'WAVE'
	    char fId[4];                	// 'fmt '
	    long pcm_header_len;    		// varies...
	    short int wFormatTag;       	// member description for wFormatTag
	    short int nChannels;        	// 1, 2 for stereo data is (l, r) pairs
	    long  nSamplesPerSec;    		// member description for nSamplesPerSec
	    long  nAvgBytesPerSec;   		// member description for nAvgBytesPerSec
	    short int nBlockAlign;      	// member description for nBlockAlign
	    short int nBitsPerSample;   	// member description for nBitsPerSample
	};
public:
	virtual bool Open(const std::string & file_name);
	bool CheckWaveHead();
	int GetAvailableLen();
private:
	virtual bool Write(){return false;}
public:
	WaveFile();
	virtual ~WaveFile();
private:
	int m_iDataLen;
};

#endif /* WAVEFILE_H_ */
