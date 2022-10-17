#include "TRDPCH.h"
#include "RenderCommand.h"

#include <glad/glad.h>

namespace TRDEngine {

	static void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
			case GL_DEBUG_SEVERITY_HIGH:         TRD_LOGFATAL(message); return;
			case GL_DEBUG_SEVERITY_MEDIUM:       TRD_LOGERROR(message); return;
			case GL_DEBUG_SEVERITY_LOW:          TRD_LOGWARN(message); return;
			case GL_DEBUG_SEVERITY_NOTIFICATION: TRD_LOGTRACE(message); return;
		}

		TRD_ASSERT(false, "Unknown severity level!");
	}

	void RenderCommand::Init()
	{
#ifdef TRD_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_DEPTH_TEST);
	}

	void RenderCommand::SetClearColor(const Color& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void RenderCommand::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // TODO refactor
	}

	void RenderCommand::DrawIndexed(uint32_t indexCount)
	{
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
	}

}