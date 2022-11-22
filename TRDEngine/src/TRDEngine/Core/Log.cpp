#include "TRDPCH.h"
#include "Log.h"
#include <stdio.h>
#include <stdarg.h>

namespace TRDEngine {

	LogLevel Log::s_Level = LogLevel::Trace;

	void Log::Init(LogLevel level)
	{
		s_Level = level;
		TRD_LOGWARN("Initialized Log!");
	}

	void Log::Shutdown()
	{
		TRD_LOGWARN("Shutdown Log!");
	}

	void Log::LogMessage(LogLevel level, const char* message, ...)
	{
		if (s_Level > level) return;

		va_list args;
		va_start(args, message);

		switch (level)
		{
		case TRDEngine::LogLevel::Trace:
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		case TRDEngine::LogLevel::Debug:
			printf("\033[32m");
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		case TRDEngine::LogLevel::Info:
			printf("\033[36m");
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		case TRDEngine::LogLevel::Warn:
			printf("\033[33m");
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		case TRDEngine::LogLevel::Error:
			printf("\033[31m");
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		case TRDEngine::LogLevel::Fatal:
			printf("\033[41m\033[1m");
			printf("[TRD ENGINE] ");
			vprintf(message, args);
			printf("\033[0m\n");
			break;
		default:
			break;
		}
	}

}
