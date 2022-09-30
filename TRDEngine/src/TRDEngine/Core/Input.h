#pragma once

#include "TRDEngine/Core/KeyCode.h"
#include "TRDEngine/Core/MouseCode.h"

#include <utility>
#include <unordered_map>

namespace TRDEngine {

	class Input
	{
	public:
		static bool IsKeyDown(KeyCode keycode);
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsKeyReleased(KeyCode keycode);
		static bool IsKeyUp(KeyCode keycode);

		static bool IsMouseButtonDown(MouseCode button);
		static bool IsMouseButtonPressed(MouseCode button);
		static bool IsMouseButtonReleased(MouseCode button);
		static bool IsMouseButtonUp(MouseCode button);

		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		static void OnUpdate();

	private:
		static std::unordered_map<int, bool> s_KeyMaps;
		static std::unordered_map<int, bool> s_MouseMaps;
	};

}