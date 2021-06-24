#pragma once


#ifdef PAIZO_PLATFORM_WINDOWS
	#ifdef PAIZO_DYNAMIC_LINK
		#ifdef PAIZO_BUILD_DLL
			#define PAIZO_API __declspec(dllexport)
		#else
			#define PAIZO_API __declspec(dllimport)
		#endif
	#else
		#define PAIZO_API 
	#endif
#endif // PAZIOL_PLATFORM_WINDOWS

#ifdef PAIZO_ENABLE_ASSERTS
	#define PAIZO_ASSERT(x, ...) { if (!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define PAIZO_CORE_ASSERT(x, ...) { if (!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#else
	#define PAIZO_ASSERT(x, ...)
	#define PAIZO_CORE_ASSERT(x, ...)
#endif // END EL_ENABLE_ASSERTS

#define BIT(x) (1 << x)   