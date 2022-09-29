#pragma once

#ifdef _WIN32
	#ifdef _MSC_VER
		#define TRD_DEBUGBREAK() __debugbreak();
	#elif
		#define TRD_DEBUGBREAK() __builtin_trap();
	#endif // _MSC_VER
#elif
	#include <signal.h>
	#define TRD_DEBUGBREAK() raise(SIGTRAP)
#endif // _WIN32
