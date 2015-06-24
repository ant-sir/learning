/*
 * LogXML.h
 *
 *  Created on: 2015年6月5日
 *      Author: zyl
 */

#ifndef LOGXML_H_
#define LOGXML_H_
#include "pugixml.hpp"
#include <CFile.h>

class LogXML: public CFile
{
public:
	LogXML();
	virtual ~LogXML();
public:
	void PrepareOutPutFile();
	void AppendCase(pugi::xml_node node);
	void Save();
private:
	pugi::xml_document o_xmlDoc;
	pugi::xml_node o_RootNode;
};

#endif /* LOGXML_H_ */
