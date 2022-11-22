#include "TRDPCH.h"
#include "GraphicsContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace TRDEngine {

	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TRD_ASSERT(windowHandle, "Window handle is null!");
	}

	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TRD_ASSERT(status, "Failed to initialize Glad!");

		TRD_LOGINFO("OpenGL Info:");
		TRD_LOGINFO("  Vendor: %s", glGetString(GL_VENDOR));
		TRD_LOGINFO("  Renderer: %s", glGetString(GL_RENDERER));
		TRD_LOGINFO("  Version: %s", glGetString(GL_VERSION));

		TRD_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "The Random Dungeon requires at least OpenGL version 4.5!");
	}

	void GraphicsContext::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}