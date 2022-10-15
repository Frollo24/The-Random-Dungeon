#include "TRDPCH.h"
#include "RenderSystem.h"

namespace TRDEngine {

	std::vector<Ref<Graphics>> RenderSystem::m_GraphicsComponents{};

	void RenderSystem::Register(const Ref<Graphics>& graphics)
	{
		m_GraphicsComponents.push_back(graphics);
	}

	void RenderSystem::Render()
	{
		for (const auto& graphics : m_GraphicsComponents)
			graphics->Render();
	}

	void RenderSystem::Update()
	{
		for (const auto& graphics : m_GraphicsComponents)
			graphics->Update();
	}

}