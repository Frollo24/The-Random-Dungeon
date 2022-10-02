#include "TRDPCH.h"
#include "WindowSystem.h"

#include <GLFW/glfw3.h>

namespace TRDEngine {

	bool WindowSystem::s_GLFWInitialized = false;

	void WindowSystem::Init()
	{
		TRD_LOGWARN("Initialized WindowSystem!");

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			TRD_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}
	}

	void WindowSystem::Shutdown()
	{
		TRD_LOGWARN("Shutdown WindowSystem!");

		glfwTerminate();
	}

}
