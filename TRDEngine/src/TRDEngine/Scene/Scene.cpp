#include "TRDPCH.h"
#include "Scene.h"

#include "TRDEngine/Systems/TransformSystem.h"
#include "TRDEngine/Systems/RenderSystem.h"

namespace TRDEngine {

	Ref<Camera> Scene::s_ActiveCamera = nullptr;

	Scene::Scene()
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
		for (const auto& object : m_GameObjects)
			object->Update();

		TransformSystem::Update();
		RenderSystem::Update();
	}

	void Scene::AddGameObject(const Ref<GameObject>& gameObject)
	{
		m_GameObjects.push_back(gameObject);
	}

}