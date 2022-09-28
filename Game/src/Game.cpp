#define TRD_ENTRY_POINT
#include <TRDEngine.h>

class Game : public TRDEngine::Application {
public:
	Game() = default;
	virtual ~Game() = default;
};

TRDEngine::Application* TRDEngine::CreateApplication() {
	return new Game();
}