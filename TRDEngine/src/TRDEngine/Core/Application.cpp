#include "TRDPCH.h"
#include "Application.h"

#include "Assert.h"

namespace TRDEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TRD_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = CreateScope<Window>();
		m_Window->SetEventCallback(TRD_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		s_Instance = nullptr;
	}

	void Application::Run()
	{
		while (m_Running) {

			if (Input::IsKeyDown(KeyCode::W)) {
				TRD_LOGINFO("W key down!");
			}
			if (Input::IsKeyUp(KeyCode::W)) {
				TRD_LOGINFO("W key up!");
			}

			Input::OnUpdate();
			m_Window->OnUpdate();
			m_Running = !m_Window->ShouldClose();
		}
	}

	void Application::OnEvent(Event& e)
	{
		TRD_LOGTRACE("%s", e.ToString().c_str());

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TRD_BIND_EVENT_FN(Application::OnWindowClose));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		TRD_LOGINFO("Window \"%s\" closed", e.GetTitle().c_str());
		return true;
	}
}