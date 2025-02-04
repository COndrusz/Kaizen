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

#ifdef KZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { KZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define KZ_CORE_ASSERT(x, ...) { if(!(x)) { KZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define KZ_ASSERT(x, ...)
	#define KZ_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)