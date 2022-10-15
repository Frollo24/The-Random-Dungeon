#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/GameObject.h"

namespace TRDEngine {

	class Scene {
	public:
		Scene(const Ref<GameObject>& gameObject);

		void Create();
		void Render();
		void Update();

	private:
		Ref<GameObject> m_GameObject = nullptr;
	};

}