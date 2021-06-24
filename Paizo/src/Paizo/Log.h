#pragma once

#include "pzpch.h"

#include "Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Paizo
{
	class PAIZO_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;


	};

}


#define PAIZO_CORE_LOG(...)       ::Paizo::Log::GetCoreLogger()->log(__VA_ARGS__)
#define PAIZO_CORE_ERROR(...)     ::Paizo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PAIZO_CORE_WARN(...)      ::Paizo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PAIZO_CORE_INFO(...)      ::Paizo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PAIZO_CORE_TRACE(...)     ::Paizo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PAIZO_CORE_FATAL(...)     ::Paizo::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define EL_LOG(...)            ::Paizo::Log::GetClientLogger()->log(__VA_ARGS__)
#define EL_ERROR(...)          ::Paizo::Log::GetClientLogger()->error(__VA_ARGS__)
#define EL_WARN(...)           ::Paizo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EL_INFO(...)		   ::Paizo::Log::GetClientLogger()->info(__VA_ARGS__)
#define EL_TRACE(...)	       ::Paizo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EL_FATAL(...)		   ::Paizo::Log::GetClientLogger()->fatal(__VA_ARGS__)

