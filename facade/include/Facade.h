/*
 * Facade.h
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#ifndef FACADE_H_
#define FACADE_H_

class Reader;
class Writer;
class Cipher;

class Facade
{
public:
	Facade();
	virtual ~Facade();
public:
	void FileEncrypt();
private:
	Reader* m_reader;
	Writer* m_writer;
	Cipher* m_cipher;

};

#endif /* FACADE_H_ */
