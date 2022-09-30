#pragma once

#include "Base.h"
#include "Input.h"
#include "TRDEngine/Window/Window.h"
#include "TRDEngine/Events/Event.h"
#include "TRDEngine/Events/WindowEvent.h"

namespace TRDEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		inline static Application& Instance() { return *s_Instance; }

		void Run();
		void OnEvent(Event& e);

		Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		Scope<Window> m_Window;

		static Application* s_Instance;
		bool m_Running = true;
	};

	// To be defined by client
	Application* CreateApplication();

}