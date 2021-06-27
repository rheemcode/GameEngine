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

#ifdef PAIZO_DEBUG
	#define PAIZO_ASSERT(x, ...) { if (!(x)) {PAIZO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define PAIZO_CORE_ASSERT(x, ...) { if (!(x)) {PAIZO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	
#define  PAIZO_ERR_FAIL_COND(m_cond, m_retval)																				        \
	if (m_cond)																												        \
	{																														        \
		PAIZO_ERROR("{0}, {1}, {2}, Condition: {3} is true. Returning: {4}", __FUNCTION__, __FILE__, __LINE__, #m_cond, #m_retval); \
		return m_retval;																										    \
	}																															    \
	else ((void)0);
#define  PAIZO_ERR_FAIL_COND_N(m_cond)																				              \
	if (m_cond)																												      \
	{																														      \
		PAIZO_ERROR("{0}, {1}, {2}, Condition: {3} is true.", __FUNCTION__, __FILE__, __LINE__, #m_cond);                         \
		return;																										              \
	}																															  \
	else ((void)0);

#define  PAIZO_ERR_FAIL_COND_MSG(m_cond, m_msg)																				      \
	if (m_cond)																												      \
	{																														      \
		PAIZO_ERROR("{0}, {1}, {2}, Condition: {3} is true.", __FUNCTION__, __FILE__, __LINE__, m_msg); \
		return m_retval;																										  \
	}																															  \
	else ((void)0);

#define PAIZO_CRASH_MSG(m_msg) { PAIZO_ERROR("{0}, {1}, {2}, FATAL: Method/Function called: {3}.", __FUNCTION__, __FILE__, __LINE__, m_msg); }

#else
	#define PAIZO_ASSERT(x, ...)
	#define PAIZO_CORE_ASSERT(x, ...)
#endif // END EL_ENABLE_ASSERTS

#define BIT(x) (1 << x)   