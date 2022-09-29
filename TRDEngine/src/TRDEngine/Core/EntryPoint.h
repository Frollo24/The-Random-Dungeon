#pragma once
#include "TRDEngine.h"

extern TRDEngine::Application* TRDEngine::CreateApplication(); // To be defined in client

namespace TRDEngine {

	int Main(int ArgC, char** ArgV) {
		Log::Init();
		WindowSystem::Init();

		auto app = TRDEngine::CreateApplication();
		app->Run();
		delete app;

		WindowSystem::Shutdown();
		Log::Shutdown();
		return 0;
	}
}

int main(int argc, char** argv) {
	return TRDEngine::Main(argc, argv);
}