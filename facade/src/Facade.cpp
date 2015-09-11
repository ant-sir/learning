/*
 * Facade.cpp
 *
 *  Created on: 2015年7月23日
 *      Author: zyl
 */

#include "Facade.h"

#include "Reader.h"
#include "Writer.h"
#include "Cipher.h"

Facade::Facade()
: m_reader(nullptr)
, m_writer(nullptr)
, m_cipher(nullptr)
{
	m_reader = new Reader();
	m_writer = new Writer();
	m_cipher = new Cipher();

}

Facade::~Facade()
{
	// TODO Auto-generated destructor stub
}

void Facade::FileEncrypt()
{
	m_reader->Read();
	m_cipher->Ciphe();
	m_writer->Write();
}
