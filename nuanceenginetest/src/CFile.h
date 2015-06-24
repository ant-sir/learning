/*
 * CFile.h
 *
 *  Created on: 2015年6月4日
 *      Author: zyl
 */

#ifndef CFILE_H_
#define CFILE_H_
#include <string>

class CFile
{
public:
	CFile();
	CFile(int mode);
	virtual ~CFile();
	virtual bool Open(const std::string & file_name);
	virtual bool Close();
	virtual int  Read(void* buf, int len);
	virtual int  Write(const void* buf, int len);
protected:
	int m_file;
	int m_mode;
};

#endif /* CFILE_H_ */
