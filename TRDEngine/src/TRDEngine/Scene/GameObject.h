#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/Transform.h"
#include "TRDEngine/Scene/Graphics.h"

namespace TRDEngine {

	class GameObject
	{
	public:
		GameObject();

		void AddGraphics(const Ref<Graphics>& graphics);

		inline const Ref<Transform>& GetTransform() { return m_Transform; }

		virtual void Create() {}
		virtual void Update() {}

	private:
		Ref<Transform> m_Transform = nullptr;
		Ref<Graphics> m_Graphics = nullptr;
	};

}