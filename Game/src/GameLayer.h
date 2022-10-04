#pragma once
#include <TRDEngine.h>

class GameLayer : public TRDEngine::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void OnEvent(TRDEngine::Event& e) override;
};