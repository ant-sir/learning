/*
 * EngineTest.h
 *
 *  Created on: 2015年5月20日
 *      Author: zyl
 */

#ifndef ENGINETEST_H_
#define ENGINETEST_H_

#include <list>
#include <memory>
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
#include <boost/bind.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_array.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "Vr_Asr_Engine.h"
#include "Vr_Asr_Event_Phase.h"
#include "Vr_Asr_Event_Notify.h"
#include "Vr_Asr_Event_Result.h"
#include "Vr_Asr_Request_Recognize.h"
#include "Vr_Asr_Request_Context_List_Update.h"
#include "Vr_Asr_Term.h"
#include "CL_WaitObj.h"
#include "C_IAudio_In.h"
#include "LogXML.h"

using std::string;
class FileInPut;
class EngineTest
{
public:
    enum TestType
	{
    	RECOGNIZE = 0,
		VOICETAG
	};
public:
	EngineTest();
	virtual ~EngineTest();
public:
    virtual void Initialize(const std::string filename);
    virtual void TestRecognize(TestType type);
    
    void
    Update
	(
    	string stringFile,
    	string stringContext,
    	int b_Delete,
    	int b_Clear
	);

private:
    void RecognizeEventPhase(N_Vr::N_Asr::C_Event_Phase const & eventPhaseType);
    void RecognizeEventNotify(N_Vr::N_Asr::C_Event_Notify const & EventNotifyType);
    void RecognizeEventResult(N_Vr::N_Asr::C_Event_Result const & EventResultType);
    std::list<std::shared_ptr<FileInPut>>
	ParseInPutXML(std::string filename);
    bool IsFileExit(std::string filename);

private:
    EngineTest(const EngineTest&);

    void operator= (const EngineTest&);

private:
    boost::shared_ptr<N_Vr::N_Asr::C_Engine> m_spEngine;
    boost::shared_ptr<C_IAudio_In> m_spIAudioIn;
    std::list<std::shared_ptr<FileInPut>> m_FileList;
    CL_WaitObj m_WaitObj;
    LogXML m_OutPutFile;
    int m_bTestType;
};

#endif /* ENGINETEST_H_ */
