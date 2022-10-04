#define TRD_ENTRY_POINT
#include <TRDEngine.h>

#include "GameLayer.h"

class Game : public TRDEngine::Application {
public:
	Game();
	virtual ~Game() = default;
};

Game::Game() {
	PushLayer(new GameLayer());
}

TRDEngine::Application* TRDEngine::CreateApplication() {
	return new Game();
}