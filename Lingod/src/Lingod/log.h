#pragma once
#include "Core.h"
#include "spdlog/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Lingod {


	class  LG_API  log
	{
	public:
		log() {};
		~log() {};

		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

/* Core macros*/
#define LG_CORE_INFO(...)			::Lingod::log::GetCoreLogger()->info(__VA_ARGS__)
#define LG_CORE_ERROR(...)		::Lingod::log::GetCoreLogger()->error(__VA_ARGS__)
#define LG_CORE_WARN(...)		::Lingod::log::GetCoreLogger()->warn(__VA_ARGS__)
#define LG_CORE_TRACE(...)		::Lingod::log::GetCoreLogger()->trace(__VA_ARGS__)
#define LG_CORE_FATAL(...)		::Lingod::log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client macros*/
#define LG_INFO(...)			::Lingod::log::GetClientLogger()->info(__VA_ARGS__)
#define LG_ERROR(...)			::Lingod::log::GetClientLogger()->error(__VA_ARGS__)
#define LG_WARN(...)			::Lingod::log::GetClientLogger()->warn(__VA_ARGS__)
#define LG_TRACE(...)			::Lingod::log::GetClientLogger()->trace(__VA_ARGS__)
#define LG_FATAL(...)			::Lingod::log::GetClientLogger()->fatal(__VA_ARGS__)


