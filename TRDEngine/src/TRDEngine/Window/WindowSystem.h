#pragma once

#include "TRDEngine/Core/Base.h"

namespace TRDEngine {

	class WindowSystem
	{
	public:
		static void Init();
		static void Shutdown();

	private:
		static bool s_GLFWInitialized;
	};

}
