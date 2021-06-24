#pragma once

namespace Paizo
{
	enum Weekday {
		DAY_SUNDAY,
		DAY_MONDAY,
		DAY_TUESDAY,
		DAY_WEDNESDAY,
		DAY_THURSDAY,
		DAY_FRIDAY,
		DAY_SATURDAY
	};

	enum Month {
		/// Start at 1 to follow Windows SYSTEMTIME structure
		/// https://msdn.microsoft.com/en-us/library/windows/desktop/ms724950(v=vs.85).aspx
		MONTH_JANUARY = 1,
		MONTH_FEBRUARY,
		MONTH_MARCH,
		MONTH_APRIL,
		MONTH_MAY,
		MONTH_JUNE,
		MONTH_JULY,
		MONTH_AUGUST,
		MONTH_SEPTEMBER,
		MONTH_OCTOBER,
		MONTH_NOVEMBER,
		MONTH_DECEMBER
	};

	enum LogLevel
	{
		TRACE,
		DEBUG,
		INFO,
		WARN,
		ERR,
		CRITICAL
	};

	struct Date {
		int year;
		Month month;
		int day;
		Weekday weekday;
		bool dst;
	};

	struct Time {
		int hour;
		int min;
		int sec;
	};

	class OS
	{
	public:
		virtual void Init() = 0;
		virtual void Run() = 0;
		virtual const char* GetName() = 0;
		virtual Date GetDate() = 0;
		static OS* Get() { return s_Instance; };
		template<typename... Args>
		void StdLog(const char* msg, LogLevel level, Args&& ...args)
		{
			Log::GetCoreLogger()->log((spdlog::level::level_enum)level, msg, args);
		}
	protected:
		static OS* s_Instance;
	};

}