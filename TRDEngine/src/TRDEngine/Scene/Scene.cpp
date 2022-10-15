#include "TRDPCH.h"
#include "Scene.h"

#include "TRDEngine/Systems/RenderSystem.h"

namespace TRDEngine {

	Scene::Scene(const Ref<GameObject>& gameObject)
		: m_GameObject(gameObject)
	{
		Create();
	}

	void Scene::Create()
	{
		TRD_LOGINFO("Scene created!");
	}

	void Scene::Render()
	{
		RenderSystem::Render();
	}

	void Scene::Update()
	{
		RenderSystem::Update();
	}
}