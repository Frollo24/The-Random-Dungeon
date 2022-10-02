#include "TRDPCH.h"
#include "Input.h"

#include "TRDEngine/Core/Application.h"

#include <GLFW/glfw3.h>

namespace TRDEngine {

	std::unordered_map<int, bool> Input::s_KeyMaps;
	std::unordered_map<int, bool> Input::s_MouseMaps;

	bool Input::IsKeyDown(KeyCode keycode)
	{
		int32_t key = static_cast<int32_t>(keycode);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		if (s_KeyMaps.find(key) == s_KeyMaps.end()) s_KeyMaps[key] = GLFW_PRESS;
		bool keyState = s_KeyMaps[key];
		return state == GLFW_PRESS && !keyState;
	}

	bool Input::IsKeyPressed(KeyCode keycode)
	{
		int32_t key = static_cast<int32_t>(keycode);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS;
	}

	bool Input::IsKeyReleased(KeyCode keycode)
	{
		int32_t key = static_cast<int32_t>(keycode);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		return state == GLFW_RELEASE;
	}

	bool Input::IsKeyUp(KeyCode keycode)
	{
		int32_t key = static_cast<int32_t>(keycode);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		if (s_KeyMaps.find(key) == s_KeyMaps.end()) s_KeyMaps[key] = GLFW_RELEASE;
		bool keyState = s_KeyMaps[key];
		return state == GLFW_RELEASE && keyState;
	}

	bool Input::IsMouseButtonDown(MouseCode button)
	{
		int32_t mouse = static_cast<int32_t>(button);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouse);
		if (s_MouseMaps.find(mouse) == s_MouseMaps.end()) s_MouseMaps[mouse] = GLFW_PRESS;
		bool mouseState = s_MouseMaps[mouse];
		return state == GLFW_PRESS && !mouseState;
	}

	bool Input::IsMouseButtonPressed(MouseCode button)
	{
		int32_t mouse = static_cast<int32_t>(button);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouse);
		return state == GLFW_PRESS;
	}

	bool Input::IsMouseButtonReleased(MouseCode button)
	{
		int32_t mouse = static_cast<int32_t>(button);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouse);
		return state == GLFW_RELEASE;
	}

	bool Input::IsMouseButtonUp(MouseCode button)
	{
		int32_t mouse = static_cast<int32_t>(button);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouse);
		if (s_MouseMaps.find(mouse) == s_MouseMaps.end()) s_MouseMaps[mouse] = GLFW_RELEASE;
		bool mouseState = s_MouseMaps[mouse];
		return state == GLFW_PRESS && mouseState;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().first;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().second;
	}

	void Input::OnUpdate()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());

		for (auto& [key, state] : s_KeyMaps)
		{
			auto newstate = glfwGetKey(window, key);
			s_KeyMaps[key] = newstate;
		}

		for (auto& [mouse, state] : s_MouseMaps)
		{
			auto newstate = glfwGetKey(window, mouse);
			s_MouseMaps[mouse] = newstate;
		}
	}

}