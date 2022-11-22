#pragma once
#include "TRDPCH.h"

namespace TRDEngine {

	enum class LogLevel : uint8_t {
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Fatal
	};

	class Log {
	public:
		static void Init(LogLevel level = LogLevel::Trace);
		static void Shutdown();

		static void LogMessage(LogLevel level, const char* message, ...);
	private:
		static LogLevel s_Level;
	};

}

#ifdef TRD_DEBUG
	#define TRD_LOGTRACE(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Trace, message, __VA_ARGS__)
	#define TRD_LOGDEBUG(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Debug, message, __VA_ARGS__)
	#define TRD_LOGINFO(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Info, message, __VA_ARGS__)
	#define TRD_LOGWARN(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Warn, message, __VA_ARGS__)
	#define TRD_LOGERROR(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Error, message, __VA_ARGS__)
	#define TRD_LOGFATAL(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Fatal, message, __VA_ARGS__)
#elif TRD_RELEASE
	#define TRD_LOGTRACE(message, ...)
	#define TRD_LOGDEBUG(message, ...)
	#define TRD_LOGINFO(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Info, message, __VA_ARGS__)
	#define TRD_LOGWARN(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Warn, message, __VA_ARGS__)
	#define TRD_LOGERROR(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Error, message, __VA_ARGS__)
	#define TRD_LOGFATAL(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Fatal, message, __VA_ARGS__)
#elif TRD_DIST
	#define TRD_LOGTRACE(message, ...)
	#define TRD_LOGDEBUG(message, ...)
	#define TRD_LOGINFO(message, ...)
	#define TRD_LOGWARN(message, ...)
	#define TRD_LOGERROR(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Error, message, __VA_ARGS__)
	#define TRD_LOGFATAL(message, ...) ::TRDEngine::Log::LogMessage(TRDEngine::LogLevel::Fatal, message, __VA_ARGS__)
#endif