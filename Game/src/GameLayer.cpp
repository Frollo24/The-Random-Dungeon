#include "GameLayer.h"

using namespace TRDEngine;

static Ref<Scene> s_Scene;
static Ref<GameObject> s_GameObject;

GameLayer::GameLayer() : Layer("Game Layer")
{
	s_GameObject = CreateRef<GameObject>();
	s_GameObject->AddGraphics(CreateRef<Graphics>());

	s_Scene = CreateRef<Scene>(s_GameObject);
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
