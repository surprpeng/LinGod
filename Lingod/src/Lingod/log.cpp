#include "lgpch.h"
#include "log.h"


namespace Lingod {

	 std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	 std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	 void Lingod::log::init() 
	 {
		 spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
		 s_CoreLogger = spdlog::stdout_color_mt("Lingod");
		 s_CoreLogger->set_level(spdlog::level::trace);

		 s_ClientLogger = spdlog::stdout_color_mt("app");
		 s_ClientLogger->set_level(spdlog::level::trace);

	};

}



