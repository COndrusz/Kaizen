#pragma once

#ifdef KZ_PLATFORM_WINDOWS
	#ifdef KZ_BUILD_DLL
		#define KAIZEN_API __declspec(dllexport)
	#else
		#define KAIZEN_API __declspec(dllimport)
	#endif
#else
	#error Kaizen only supports windows
#endif