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


// ASSERTION
#ifdef LG_ENABLE_ASSERTS
		#ifdef LG_PLATFORM_WINDOWS
		#define LG_ASSERT(x,...) {if (!(x)) { LG_ERROR("Assertion Failed! {0}", __VA_ARGS__); __debugbreak(); } }
		#define LG_CORE_ASSERT(x,...) {if (!(x)) { LG_CORE_ERROR("Assertion Failed! {0}", __VA_ARGS__); __debugbreak(); } }
#endif
#else
		#define LG_ASSERT(x,...)
		#define LG_CORE_ASSERT(x,...)
#endif