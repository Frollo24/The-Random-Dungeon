#include "Application.h"

#include "Assert.h"

namespace TRDEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TRD_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
	}
	Application::~Application()
	{
		s_Instance = nullptr;
	}
	void Application::Run()
	{
		while (m_Running);
	}
}