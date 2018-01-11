// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "libusb.h"

#ifdef _WIN64
#pragma comment(lib, "../libusb/libusb-1.0-win64-vs2013-static.lib")
#else
#pragma comment(lib, "../libusb/libusb-1.0-win32-vs2013-static.lib")
#endif

// need be initialized
extern "C" CRITICAL_SECTION mm;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		InitializeCriticalSection(&mm);
		libusb_init(NULL);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		libusb_exit(NULL);
		break;
	}
	return TRUE;
}

