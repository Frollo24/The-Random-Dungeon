#pragma once

#include "TRDEngine/Core/Base.h"

#include <functional>
struct GLFWwindow;

namespace TRDEngine {

	struct WindowProps {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string title = "The Random Dungeon Engine", uint32_t width = 1600, uint32_t height = 900)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
	public:
		Window(const WindowProps& props = WindowProps());
		~Window();

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height; }

		void SetVSync(bool enabled);
		inline bool IsVSync() const { return m_Data.VSync; };

		inline GLFWwindow* GetNativeWindow() const { return m_Window; }
		bool ShouldClose() const;

	private:
		void Init(const WindowProps& props);
		void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width = 0, Height = 0;
			bool VSync = false;
		};

		WindowData m_Data;
	};

}