#pragma once

#include "Base.h"
#include "LayerStack.h"

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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		Scope<Window> m_Window;
		LayerStack m_LayerStack;

		static Application* s_Instance;
		bool m_Running = true;
		float m_LastFrameTime = 0.0f;
	};

	// To be defined by client
	Application* CreateApplication();

}