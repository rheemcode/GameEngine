#pragma once

#include "elpch.h"

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Electro
{
	class ELECTRO_API Log
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


#define EL_CORE_LOG(...)       ::Electro::Log::GetCoreLogger()->log(__VA_ARGS__)
#define EL_CORE_ERROR(...)     ::Electro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EL_CORE_WARN(...)      ::Electro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EL_CORE_INFO(...)      ::Electro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EL_CORE_TRACE(...)     ::Electro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EL_CORE_FATAL(...)     ::Electro::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define EL_LOG(...)            ::Electro::Log::GetClientLogger()->log(__VA_ARGS__)
#define EL_ERROR(...)          ::Electro::Log::GetClientLogger()->error(__VA_ARGS__)
#define EL_WARN(...)           ::Electro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EL_INFO(...)		   ::Electro::Log::GetClientLogger()->info(__VA_ARGS__)
#define EL_TRACE(...)	       ::Electro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EL_FATAL(...)		   ::Electro::Log::GetClientLogger()->fatal(__VA_ARGS__)

