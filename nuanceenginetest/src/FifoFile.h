/**
 * Copyright @ 2014 - 2017 Suntec Software(Shanghai) Co., Ltd.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are NOT permitted except as agreed by
 * Suntec Software(Shanghai) Co., Ltd.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

/**
 * @file VC_IAudioInFile.h
 * @brief inteface
 *
 *
 * @attention used for C++ only.
 */
#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif


#ifndef _FIFOFILE_H_
#define _FIFOFILE_H_

#include <string>
 #include <limits.h>

class FifoFile
{
public:
	FifoFile();
    virtual ~FifoFile();

    bool CreatePipe();
    bool ClosePipe();
    bool OpenForRead();
    bool OpenForWrite();
    bool CheckDataAvailable();
    int ReadPipe(void *buf,int len=PATH_MAX);
    void ClearPipe();
    bool WritePipe(const void *buf,int len=PATH_MAX);

private:
    std::string strPipeName;
    int nfdRead;
    int nfdWrite;
};

#endif //_FIFOFILE_H_
/* EOF */

