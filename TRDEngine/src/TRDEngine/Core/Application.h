#pragma once

namespace TRDEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		inline static Application& Instance() { return *s_Instance; }

		void Run();

	private:
		static Application* s_Instance;
		bool m_Running = true;
	};

	// To be defined by client
	Application* CreateApplication();

}