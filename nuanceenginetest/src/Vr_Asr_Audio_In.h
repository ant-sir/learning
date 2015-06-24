/**
 * Copyright @ 2015 - 2016 Suntec Software(Shanghai) Co., Ltd.
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
 * @file Vr_Common_Audio_In.h
 * @brief Common class define
 *
 *
 * @attention used for C++ only.
 */

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#ifndef __Vr_Common_Audio_In_h__
#define __Vr_Common_Audio_In_h__
#include <stddef.h>
namespace N_Vr
{

namespace N_Asr
{

/**
 * @brief The C_Audio_In class
 *
 * C_Audio_In class
 */
class C_Audio_In
{
  public:

    enum E_Audio_In_Type
    {
        E_Audio_In_Type_None,
        E_Audio_In_Type_Mic_Nuance,
        E_Audio_In_Type_Mic_Audio_Service,
        E_Audio_In_Type_File_Linux,
        E_Audio_In_Type_File_Win,
    };

    static
    C_Audio_In * // [R] Created instance.
    Factory
    (
        E_Audio_In_Type e_Audio_In_Type
    ); // [F] Factory.

    virtual
    int // [R] 0 for succeed, 1 for failed.
    M_Fn_Start() = 0;

    virtual
    int // [R] 0 for succeed, 1 for failed.
    M_Fn_Stop() = 0;

    virtual
    int // [R] 0 for succeed, 1 for failed.
    M_Fn_Data_Available_Check
    (
        bool * pb_Data_Available
    ) = 0;

    virtual
    int // [R] 0 for succeed, 1 for failed.
    M_Fn_Data_Fetch
    (
        void ** ppvoid_Buffer,
        size_t * pi_Size
    ) = 0;

    virtual
    int // [R] 0 for succeed, 1 for failed.
    M_Fn_Data_Return
    (
        void * const & rpvoid_Buffer
    ) = 0;

    virtual
    ~C_Audio_In(); // [F]Destructor

    explicit
    C_Audio_In(); // [F]Constructor of Default

  protected:

    C_Audio_In // [F]Constructor: Copy
    (
        C_Audio_In const & // [I]
    );

    C_Audio_In & // [R]
    operator = // [F]Operator: =
    (
        C_Audio_In const & // [I]
    );
};

} // name N_Common

} // name N_Vr

#endif
/* EOF */
