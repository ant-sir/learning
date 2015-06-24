/*
 * Vr_Common_Audio_In.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: zyl
 */

#include "Vr_Asr_Audio_In.h"
#include "C_IAudio_In.h"
namespace N_Vr
{

namespace N_Asr
{

C_Audio_In::~C_Audio_In()
{
}

C_Audio_In::C_Audio_In()
{
}

C_Audio_In *
C_Audio_In::Factory
(
    E_Audio_In_Type e_Audio_In_Type
)
{
    switch (e_Audio_In_Type)
    {
    case E_Audio_In_Type_Mic_Nuance: {
        return new C_IAudio_In;
    }
    default:
        return 0;
    }
}
}
}

