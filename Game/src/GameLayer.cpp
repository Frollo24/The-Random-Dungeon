#include "GameLayer.h"

#include <glm/gtc/matrix_transform.hpp>
using namespace TRDEngine;

class TestObject : public GameObject
{
public:
	TestObject(const std::string& name) : GameObject(name) {}

	virtual void Create() override {
		TRD_LOGWARN("Derived object created!");
	}
	virtual void Update() override {
		float movement = m_Translation * Time::DeltaTime;

		if (Input::IsKeyPressed(KeyCode::A))
			GetTransform()->Translate({ -movement, 0.0f, 0.0f });
		if (Input::IsKeyPressed(KeyCode::D))
			GetTransform()->Translate({ movement, 0.0f, 0.0f });
		if (Input::IsKeyPressed(KeyCode::S))
			GetTransform()->Translate({ 0.0f, movement, 0.0f });
		if (Input::IsKeyPressed(KeyCode::W))
			GetTransform()->Translate({ 0.0f, -movement, 0.0f });
		if (Input::IsKeyPressed(KeyCode::Q))
			GetTransform()->Translate({ 0.0f, 0.0f, -movement });
		if (Input::IsKeyPressed(KeyCode::E))
			GetTransform()->Translate({ 0.0f, 0.0f, movement });

		/** /
		if (Input::IsKeyDown(KeyCode::F))
			GetTransform()->SetPosition({ 0.0f, 0.0f, 0.5f });
		if (Input::IsKeyDown(KeyCode::B))
			GetTransform()->SetPosition({ 0.0f, 0.0f, -0.5f });
		/**/
	}

private:
	float m_Translation = 1.4f;
};

static Ref<Scene> s_Scene;
static Ref<GameObject> s_GameObject1;
static Ref<TestObject> s_GameObject2;
static Ref<Camera> s_Camera;

GameLayer::GameLayer() : Layer("Game Layer")
{
	/**/
	s_GameObject1 = CreateRef<GameObject>("GameObject 1");
	Ref<Graphics> graphics1 = CreateRef<Graphics>("assets/models/Skeleton.obj");
	graphics1->GetMaterial()->SetColor(Color(0.2f, 0.7f, 0.9f));
	s_GameObject1->AddGraphics(graphics1);
	s_GameObject1->GetTransform()->Scale({0.5f, 0.5f, 0.5f});
	//*/

	/**/
	s_GameObject2 = CreateRef<TestObject>("GameObject 2");
	Ref<Graphics> graphics2 = CreateRef<Graphics>("assets/models/Star.obj");
	graphics2->GetMaterial()->SetColor(Color(0.9f, 0.8f, 0.2f));
	s_GameObject2->AddGraphics(graphics2);
	s_GameObject2->GetTransform()->Translate({0.0f, 0.2f, -0.1f});
	s_GameObject2->GetTransform()->Scale({0.75f, 0.75f, 0.75f});
	//*/

	s_Scene = CreateRef<Scene>();
	s_Scene->AddGameObject(s_GameObject1);
	s_Scene->AddGameObject(s_GameObject2);

	s_Camera = CreateRef<Camera>(
		glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		glm::perspective(glm::radians(60.0f), (16.0f / 9.0f), 0.01f, 10.0f)
	);
	Scene::SetActiveCamera(s_Camera);
}

void GameLayer::OnAttach()
{
	TRD_LOGDEBUG("Layer %s OnAttach", m_DebugName.c_str());
}

void GameLayer::OnDetach()
{
	TRD_LOGDEBUG("Layer %s OnDetach", m_DebugName.c_str());
}

void GameLayer::OnRender()
{
	TRD_LOGDEBUG("GameLayer::Render - %f seconds", (float)Time::DeltaTime);
	s_Scene->Render();
}

void GameLayer::OnUpdate()
{
	if (Input::IsKeyDown(KeyCode::T))
		TRD_LOGINFO("GameLayer::Update - %f seconds", (float)Time::DeltaTime);

	s_Scene->Update();
}

void GameLayer::OnEvent(TRDEngine::Event& e)
{
	TRD_LOGTRACE("%s", e.ToString().c_str());
}
