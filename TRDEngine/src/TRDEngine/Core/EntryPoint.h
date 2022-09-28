#pragma once
#include "TRDEngine.h"

extern TRDEngine::Application* TRDEngine::CreateApplication(); // To be defined in client

namespace TRDEngine {

	int Main(int ArgC, char** ArgV) {
		auto app = TRDEngine::CreateApplication();
		app->Run();
		delete app;

		return 0;
	}
}

int main(int argc, char** argv) {
	return TRDEngine::Main(argc, argv);
}