#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <fstream>

#include "cmdline.h"
#include "pugixml.hpp"

class FileInPut
{
public:
    FileInPut(std::string lang, std::string partyId, std::string dialogId, std::string fileName, std::string expectResult, int eos)
        :m_sLanguage(lang)
        , m_sPartyId(partyId)
        , m_sDialogId(dialogId)
        , m_sFileName(fileName)
        , m_sExpectResult(expectResult)
        , m_nEOSTime(eos)
    {}

    virtual ~FileInPut(){}

    // for test
    void tell(std::ostream & os) const
    {
        os << "lang\t" << m_sLanguage << std::endl
            << "party\t" << m_sPartyId << std::endl
            << "dialog\t" << m_sDialogId << std::endl
            << "file\t" << m_sFileName << std::endl
            << "expect\t" << m_sExpectResult << std::endl
            << "eos\t" << m_nEOSTime << std::endl;
    }

public:
    std::string m_sLanguage;
    std::string m_sPartyId;
    std::string m_sDialogId;
    std::string m_sFileName;
    std::string m_sExpectResult;
    int         m_nEOSTime;
};

//<test>
//	<case>
//		<lang>cxh_lang1</lang>
//		<party_id>cxh_party_1</party_id>
//		<dialog_id>cxh_dailog_1</dialog_id>
//		<filename>cxh_filename_1</filename>
//		<expect_result>cxh_expect_result_1</expect_result>
//		<eos_time>1000</eos_time>
//	</case>
//</test>

class TestCaseBuilder
{
public:
    TestCaseBuilder() {}

    std::list<std::shared_ptr<FileInPut>> buildCase(const std::string& filename);

protected:
    const static std::string TEST;
    const static std::string CASE;
    const static std::string LANG;
    const static std::string PARTY_ID;
    const static std::string DIALOG_ID;
    const static std::string FILENAME;
    const static std::string EXPECT_RESULT;
    const static std::string EOS_TIME;
};

const std::string TestCaseBuilder::TEST("test");
const std::string TestCaseBuilder::CASE("case");
const std::string TestCaseBuilder::LANG("lang");
const std::string TestCaseBuilder::PARTY_ID("party_id");
const std::string TestCaseBuilder::DIALOG_ID("dialog_id");
const std::string TestCaseBuilder::FILENAME("filename");
const std::string TestCaseBuilder::EXPECT_RESULT("expect_result");
const std::string TestCaseBuilder::EOS_TIME("eos_time");

std::list<std::shared_ptr<FileInPut>> TestCaseBuilder::buildCase(const std::string& filename)
{
    std::list<std::shared_ptr<FileInPut>> inputs;

    pugi::xml_document doc;

    auto result = doc.load_file(filename.c_str());
    if (!result) {
        throw std::logic_error(result.description());
    }

    auto testCases = doc.child(TEST.c_str());
    for (auto testCase : testCases.children()) {

        std::string lang = testCase.child(LANG.c_str()).child_value();
        std::string party_id = testCase.child(PARTY_ID.c_str()).child_value();
        std::string dialog_id = testCase.child(DIALOG_ID.c_str()).child_value();
        std::string filename = testCase.child(FILENAME.c_str()).child_value();
        std::string expect_result = testCase.child(EXPECT_RESULT.c_str()).child_value();
        int eos = std::atoi(testCase.child(EOS_TIME.c_str()).child_value());

        auto pInput = std::make_shared<FileInPut>(
                lang, party_id, dialog_id, filename, expect_result, eos
            );

        inputs.push_back(pInput);
    }

    return inputs;
}

//int main(int argc, char* argv[])
//{
//    cmdline::parser cmdp;
//    cmdp.add<std::string>("inputfile", 'i', "input xml file for test case", true, "");
//    // it will auto **EXIT** if not inputfile
//    cmdp.parse_check(argc, argv);
//
//    std::cout << cmdp.get<std::string>("inputfile") << std::endl;
//
//    TestCaseBuilder builder;
//    auto inputs = builder.buildCase(cmdp.get<std::string>("inputfile"));
//
//    for (auto input : inputs) {
//        input->tell(std::cout);
//        std::cout << std::endl;
//    }
//
//	return 0;
//}

