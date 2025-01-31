#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"



namespace Kaizen 
{
	class KAIZEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define KZ_CORE_TRACE(...) ::Kaizen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KZ_CORE_INFO(...)  ::Kaizen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KZ_CORE_WARN(...)  ::Kaizen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KZ_CORE_ERROR(...) ::Kaizen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KZ_CORE_FATAL(...) ::Kaizen::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define KZ_TRACE(...) ::Kaizen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KZ_INFO(...)  ::Kaizen::Log::GetClientLogger()->info(__VA_ARGS__)
#define KZ_WARN(...)  ::Kaizen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KZ_ERROR(...) ::Kaizen::Log::GetClientLogger()->error(__VA_ARGS__)
#define KZ_FATAL(...) ::Kaizen::Log::GetClientLogger()->fatal(__VA_ARGS__)