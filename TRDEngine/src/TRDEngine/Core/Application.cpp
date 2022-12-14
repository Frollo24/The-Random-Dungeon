#include "TRDPCH.h"
#include "Application.h"

#include "Assert.h"
#include "Input.h"
#include "Time.h"

#include "TRDEngine/Renderer/Renderer.h"
#include "TRDEngine/Renderer/RenderCommand.h"

namespace TRDEngine {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TRD_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = CreateScope<Window>();
		m_Window->SetEventCallback(TRD_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();
	}

	Application::~Application()
	{
		s_Instance = nullptr;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = Window::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			Time::s_TotalTime = time;
			Time::s_DeltaTime = timestep;

			Renderer::BeginScene();
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnRender();
			Renderer::EndScene();

			Input::OnUpdate();
			m_Window->OnUpdate();
			m_Running = !m_Window->ShouldClose();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TRD_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(TRD_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
			if (e.Handled())
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		TRD_LOGINFO("Window \"%s\" closed", e.GetTitle().c_str());
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
		return true;
	}
}