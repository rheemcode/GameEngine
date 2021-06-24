#pragma once


#ifdef EL_PLATFORM_WINDOWS
	#ifdef EL_DYNAMIC_LINK
		#ifdef EL_BUILD_DLL
			#define PAIZO_API __declspec(dllexport)
		#else
			#define PAIZO_API __declspec(dllimport)
		#endif
	#else
		#define PAIZO_API 
	#endif
#endif // EL_PLATFORM_WINDOWS

#ifdef EL_ENABLE_ASSERTS
	#define EL_ASSERT(x, ...) { if (!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define EL_CORE_ASSERT(x, ...) { if (!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#else
	#define EL_ASSERT(x, ...)
	#define EL_CORE_ASSERT(x, ...)
#endif // END EL_ENABLE_ASSERTS

#define BIT(x) (1 << x)   