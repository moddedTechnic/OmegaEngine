#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Omega {

	class OMEGA_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define OM_CORE_FATAL(...) ::Omega::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define OM_CORE_ERROR(...) ::Omega::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OM_CORE_WARN(...)  ::Omega::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OM_CORE_INFO(...)  ::Omega::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OM_CORE_TRACE(...) ::Omega::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define OM_FATAL(...) ::Omega::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define OM_ERROR(...) ::Omega::Log::GetClientLogger()->error(__VA_ARGS__)
#define OM_WARN(...)  ::Omega::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OM_INFO(...)  ::Omega::Log::GetClientLogger()->info(__VA_ARGS__)
#define OM_TRACE(...) ::Omega::Log::GetClientLogger()->trace(__VA_ARGS__)

