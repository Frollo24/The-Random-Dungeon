#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/Graphics.h"

namespace TRDEngine {

	class GameObject
	{
	public:
		GameObject();

		void AddGraphics(const Ref<Graphics>& graphics);

		virtual void Create();
		virtual void Update();

	private:
		Ref<Graphics> m_Graphics = nullptr;
	};

}