#include "GameLayer.h"

using namespace TRDEngine;

GameLayer::GameLayer() : Layer("Game Layer")
{
}

void GameLayer::OnAttach()
{
	TRD_LOGDEBUG("Layer %s OnAttach", m_DebugName.c_str());
}

void GameLayer::OnDetach()
{
	TRD_LOGDEBUG("Layer %s OnDetach", m_DebugName.c_str());
}

void GameLayer::OnUpdate()
{
	TRD_LOGINFO("GameLayer::Update - %f seconds", (float)Time::DeltaTime);
}

void GameLayer::OnEvent(TRDEngine::Event& e)
{
	TRD_LOGTRACE("%s", e.ToString().c_str());
}
