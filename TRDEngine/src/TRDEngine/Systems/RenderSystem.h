#pragma once

#include "TRDPCH.h"
#include "TRDEngine/Scene/Graphics.h"

namespace TRDEngine {

	class RenderSystem
	{
	public:
		static void Register(const Ref<Graphics>& graphics);
		static void Render();
		static void Update();

	private:
		static std::vector<Ref<Graphics>> m_GraphicsComponents;
	};

}