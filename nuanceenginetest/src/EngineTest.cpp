/*
 * EngineTest.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: zyl
 */
#include <unistd.h>
#include <list>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <stdexcept>
#include <limits>
#include <iosfwd>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <boost/scoped_array.hpp>
#include <boost/shared_array.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "EngineTest.h"
#include "EngineTestDef.h"
#include "testxml.hpp"
#include "Vr_Asr_Def.h"

const std::string file_path_base("/udisk/test/wav/");

EngineTest::EngineTest()
: m_spEngine()
, m_spIAudioIn()
, m_FileList()
, m_WaitObj()
, m_OutPutFile()
, m_bTestType(-1)
{
}

EngineTest::~EngineTest()
{
}

void EngineTest::Initialize(const std::string filename)
{
	if(m_spEngine.get() == NULL)
		m_spEngine.reset(N_Vr::N_Asr::C_Engine::Factory("eng"));
	if(m_spIAudioIn.get() == nullptr)
		m_spIAudioIn.reset(new C_IAudio_In());

	if(IsFileExit(filename))
		m_FileList = ParseInPutXML(filename);
	else
		VC_ERROR("File test.xml dos't exit.");
}

void
EngineTest::Update(
    std::string stringFile,
    std::string stringContext,
    int b_Delete,
    int b_Clear
	)
{
    N_Vr::N_Asr::C_Request_Context_List_Update  ro_Request_Context_List_Update;

    ro_Request_Context_List_Update.m_string_Id_Party = "Origin";
    ro_Request_Context_List_Update.m_string_Id_Context = stringContext;
    ro_Request_Context_List_Update.m_b_Clear = b_Clear;
    ro_Request_Context_List_Update.m_function_On_Event_Notify = boost::bind(&EngineTest::RecognizeEventNotify, this, _1);
    ro_Request_Context_List_Update.m_function_On_Event_Phase = boost::bind(&EngineTest::RecognizeEventPhase, this, _1);

    std::ifstream ifstreamConfig;
    ifstreamConfig.open(stringFile.c_str());
    if(!ifstreamConfig.is_open())
    {
    	printf("file open failed!!!\n");
        return;
    }

    //BOM

    char cBOM;

    ifstreamConfig >> cBOM >> cBOM >> cBOM;
    string stringBOM;
    std::getline(ifstreamConfig, stringBOM);

    while(ifstreamConfig)
    {
        string stringLine;

        std::getline(ifstreamConfig, stringLine);

        if(stringLine.empty())
        {
            continue;
        }

		boost::shared_ptr<N_Vr::N_Asr::C_Term> spo_Term(new N_Vr::N_Asr::C_Term);
		
		spo_Term->m_string_Orthography = stringLine;

        if(b_Delete)
        {
            ro_Request_Context_List_Update.m_list_spo_Term_For_Delete.push_back(spo_Term);
        }
        else
        {
            ro_Request_Context_List_Update.m_list_spo_Term_For_Add.push_back(spo_Term);
        }
    }

    m_spEngine->Context_List_Update(ro_Request_Context_List_Update);
}

void EngineTest::RecognizeEventPhase(
		const N_Vr::N_Asr::C_Event_Phase& ro_Event_Phase)
{
	switch(ro_Event_Phase.Get_Event_Phase_Type())
	{
		case N_Vr::N_Asr::C_Event_Phase::E_Event_Phase_Type_Proc_End:
		{

			m_WaitObj.Notify();

			break;
		}
		default:
		{
			break;
		}
	}
}

void EngineTest::RecognizeEventNotify(
		const N_Vr::N_Asr::C_Event_Notify& EventNotifyType)
{
}

void EngineTest::RecognizeEventResult(
		const N_Vr::N_Asr::C_Event_Result& EventResultType)
{
	if(m_bTestType == RECOGNIZE)
	{
		std::string xml = EventResultType.Get_XML()->c_str();
		if (0 == xml.length()) {
			printf("%s\n", "asr result.str.length is 0!");
			return;
		}
		pugi::xml_document o_xmlDoc;
		o_xmlDoc.load_string(xml.c_str());
		pugi::xml_node node = o_xmlDoc.child("result");
		pugi::xml_node CurrNode = node.prepend_child("node");
		CurrNode.append_attribute("name") = "EOSTime";
		CurrNode.append_attribute("value") = (int)m_spIAudioIn->GetWaveEOSTime();
		m_OutPutFile.AppendCase(node);
	}
	else if(m_bTestType == VOICETAG)
	{
		boost::shared_array<unsigned char> tag = EventResultType.Get_Userword_Transcription();

		N_Vr::N_Asr::C_Request_Context_List_Update  ro_Request_Context_List_Update;
		ro_Request_Context_List_Update.m_string_Id_Party = "Origin";
		ro_Request_Context_List_Update.m_string_Id_Context = "";
		ro_Request_Context_List_Update.m_b_Clear = false;
		ro_Request_Context_List_Update.m_function_On_Event_Notify = boost::bind(&EngineTest::RecognizeEventNotify, this, _1);
		ro_Request_Context_List_Update.m_function_On_Event_Phase = boost::bind(&EngineTest::RecognizeEventPhase, this, _1);

		boost::shared_ptr<N_Vr::N_Asr::C_Term> spo_Term(new N_Vr::N_Asr::C_Term);
		spo_Term->m_string_Orthography = m_spIAudioIn->GetTagid();
		spo_Term->m_list_sai_Transcriptions.push_back(tag);
		ro_Request_Context_List_Update.m_list_spo_Term_For_Add.push_back(spo_Term);
		m_spEngine->Context_List_Update(ro_Request_Context_List_Update);
	}
	else
		std::cout << "RecognizeEventResult error." << std::endl;
}

void EngineTest::TestRecognize(TestType type)
{
	if(type == RECOGNIZE)
		m_bTestType = RECOGNIZE;
	else
		m_bTestType = VOICETAG;

    N_Vr::N_Asr::C_Request_Recognize recognizeRequest;

    recognizeRequest.m_spo_Audio_In = m_spIAudioIn;
    recognizeRequest.m_function_On_Event_Phase  = boost::bind(&EngineTest::RecognizeEventPhase,  this, _1);
    recognizeRequest.m_function_On_Event_Notify = boost::bind(&EngineTest::RecognizeEventNotify, this, _1);
    recognizeRequest.m_function_On_Event_Result = boost::bind(&EngineTest::RecognizeEventResult, this, _1);
    recognizeRequest.m_b_Measure_Time   = false;

	for(auto file : m_FileList)
	{
		m_WaitObj.Reset();
		std::cout << "Recognize Start()" << std::endl;
		file->tell(std::cout);

		if(file->m_sLanguage != "eng")
			m_spEngine->Language_Change(file->m_sLanguage);

		recognizeRequest.m_string_Id_Party	= file->m_sPartyId;
		recognizeRequest.m_string_Id_Dialog = file->m_sDialogId;
		m_spIAudioIn->SendWaveFileName(file_path_base + file->m_sFileName);
		if(type == RECOGNIZE)
			m_spIAudioIn->SendWaveFileEos(file->m_nEOSTime);
		else
			m_spIAudioIn->SendTagID(file->m_sExpectResult);

		if(m_spEngine.get() != NULL)
		{
			N_Vr::N_Asr::E_Result er = m_spEngine->Recognize_Start(recognizeRequest);
			if( er == 1)
				std::cout << "Recognize_Start success." << std::endl;
			else
			{
				std::cout << "Recognize_Start error:"<< er << std::endl;
				return;
			}
		}
		//wait engine read file and get the result.
		m_WaitObj.Wait();
	}
	m_OutPutFile.Save();
}

std::list<std::shared_ptr<FileInPut> > EngineTest::ParseInPutXML(
		std::string filename)
{
	TestCaseBuilder builder;
	return builder.buildCase(filename);
}

bool EngineTest::IsFileExit(std::string filename)
{
	if(access(filename.c_str(), F_OK) == 0)
		return true;
	return false;
}
