#pragma once

#include "Log.h"
#include "TRDEngine/Debug/Debug.h"

#ifdef TRD_DEBUG
	#define TRD_ENABLE_ASSERTS
#endif // TRD_DEBUG

#ifdef TRD_ENABLE_ASSERTS
	#define TRD_VERIFY(x) { if(!(x)) { TRD_LOGERROR("Verification Failed at File: %s; Line: %i", __FILE__, __LINE__); TRD_DEBUGBREAK(); } }
	#define TRD_ASSERT(x, ...) { if(!(x)) { TRD_LOGERROR("Assertion Failed: %s", __VA_ARGS__); TRD_DEBUGBREAK(); } }
#else
	#define TRD_VERIFY(x)
	#define TRD_ASSERT(x, ...)
#endif // TRD_ENABLE_ASSERTS