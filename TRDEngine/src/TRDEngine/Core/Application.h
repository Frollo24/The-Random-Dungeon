#pragma once

#include "Base.h"
#include "TRDEngine/Window/Window.h"

namespace TRDEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		inline static Application& Instance() { return *s_Instance; }

		void Run();

	private:
		Scope<Window> m_Window;

		static Application* s_Instance;
		bool m_Running = true;
	};

	// To be defined by client
	Application* CreateApplication();

}