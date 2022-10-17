#include "GameLayer.h"

using namespace TRDEngine;

class TestObject : public GameObject
{
public:
	virtual void Create() override {
		TRD_LOGWARN("Derived object created!");
	}
	virtual void Update() override {
		GetTransform()->Translate({m_Translation, 0.0f, 0.0f});

		m_Translation += m_Offset * Time::DeltaTime;
		TRD_LOGINFO("%f", m_Translation);

		if (m_Translation <= -m_Bounds || m_Translation >= m_Bounds) {
			m_Offset = -m_Offset;
		}
	}

private:
	float m_Translation = 0.0f, m_Offset = 0.1f, m_Bounds = 0.025f;
};

static Ref<Scene> s_Scene;
static Ref<GameObject> s_GameObject1;
static Ref<TestObject> s_GameObject2;

GameLayer::GameLayer() : Layer("Game Layer")
{
	s_GameObject1 = CreateRef<GameObject>();
	auto graphics1 = CreateRef<Graphics>();
	graphics1->SetColor(Color(0.2f, 0.9f, 0.7f));
	s_GameObject1->AddGraphics(graphics1);

	s_GameObject2 = CreateRef<TestObject>();
	auto graphics2 = CreateRef<Graphics>();
	graphics2->SetColor(Color(0.9f, 0.2f, 0.2f));
	s_GameObject2->AddGraphics(graphics2);
	s_GameObject2->GetTransform()->Translate({0.0f, 0.3f, 0.1f});

	s_Scene = CreateRef<Scene>();
	s_Scene->AddGameObject(s_GameObject1);
	s_Scene->AddGameObject(s_GameObject2);
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
