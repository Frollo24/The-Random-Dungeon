#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/GameObject.h"
#include "TRDEngine/Renderer/Camera.h"

namespace TRDEngine {

	class Scene {
	public:
		Scene();

		void Create();
		void Render();
		void Update();

		void AddGameObject(const Ref<GameObject>& gameObject);
		static const Ref<Camera>& GetActiveCamera() { return s_ActiveCamera; }
		static void SetActiveCamera(const Ref<Camera>& camera) { s_ActiveCamera = camera; }

	private:
		std::vector<Ref<GameObject>> m_GameObjects{};
		static Ref<Camera> s_ActiveCamera;
	};

}