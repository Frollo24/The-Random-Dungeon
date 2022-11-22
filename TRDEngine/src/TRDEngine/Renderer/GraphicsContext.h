#pragma once

#include "TRDEngine/Core/Base.h"

struct GLFWwindow;

namespace TRDEngine {

	class GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* windowHandle);
		void Init();
		void SetVSync(bool enabled);
		void SwapBuffers();

	private:
		GLFWwindow* m_WindowHandle;
	};

}