// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

//#define EXPORT __declspec(dllexport)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

//extern "C" int testProcASM(int testInt);

//extern "C" EXPORT int testProc(int testInt)
//{
//	return testProcASM(testInt);
//}
