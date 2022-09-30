#pragma once

#define BIT(x) (1 << x)

#define TRD_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#include "Assert.h"
#include "Log.h"
#include "Memory.h"