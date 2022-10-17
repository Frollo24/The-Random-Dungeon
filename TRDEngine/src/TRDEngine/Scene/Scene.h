#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/GameObject.h"

namespace TRDEngine {

	class Scene {
	public:
		Scene();

		void Create();
		void Render();
		void Update();

		void AddGameObject(const Ref<GameObject>& gameObject);

	private:
		std::vector<Ref<GameObject>> m_GameObjects{};
	};

}