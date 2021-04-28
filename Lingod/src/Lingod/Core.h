#pragma once
#ifdef LG_PLAYFORM_WINDOWS
	#ifdef LG_BUILD_DLL
		#define  LG_API  _declspec(dllexport) 
	#else
		#define LG_API   _declspec(dllimport)
	#endif
#else
	#error Lingod only support window!
#endif


#define BIT(x)  (1<<x)