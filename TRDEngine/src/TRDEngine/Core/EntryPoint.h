#pragma once
#include "TRDEngine.h"

extern TRDEngine::Application* TRDEngine::CreateApplication(); // To be defined in client

namespace TRDEngine {

	int Main(int ArgC, char** ArgV) {
		Log::Init();
		TRD_LOGWARN("Initialized Log!");
		TRD_LOGDEBUG("Var = %i", 5);

		TRD_ASSERT(false, "Assertion test");
		TRD_VERIFY(false);

		auto app = TRDEngine::CreateApplication();
		app->Run();
		delete app;

		Log::Shutdown();
		return 0;
	}
}

int main(int argc, char** argv) {
	return TRDEngine::Main(argc, argv);
}