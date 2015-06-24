/*
 * LogXML.cpp
 *
 *  Created on: 2015年6月5日
 *      Author: zyl
 */
#include <iostream>
#include <sstream>
#include <LogXML.h>
#include "EngineTestDef.h"
LogXML::LogXML()
{
	// TODO Auto-generated constructor stub

}

LogXML::~LogXML()
{
	// TODO Auto-generated destructor stub
}

void LogXML::PrepareOutPutFile()
{
	pugi::xml_node decl = o_xmlDoc.prepend_child(pugi::node_declaration);
	decl.append_attribute("version") = "1.0";
	decl.append_attribute("encoding") = "UTF-8";
	o_RootNode = o_xmlDoc.append_child("output");
}

void LogXML::AppendCase(pugi::xml_node node)
{
	o_RootNode.append_copy(node);
}

void LogXML::Save()
{
	o_xmlDoc.save_file("/udisk/testout.xml");
}
