#include "Application.h"

namespace TRDEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
	}
	Application::~Application()
	{
		s_Instance = nullptr;
	}
	void Application::Run()
	{
		while (true);
	}
}