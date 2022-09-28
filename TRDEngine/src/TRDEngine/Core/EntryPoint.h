#pragma once
#include "TRDEngine.h"

extern TRDEngine::Application* TRDEngine::CreateApplication(); // To be defined in client

namespace TRDEngine {

	int Main(int ArgC, char** ArgV) {
		Log::Init();
		TRD_LOGWARN("Initialized Log!");
		TRD_LOGTRACE("Var = %i", 5);
		TRD_LOGDEBUG("Var = %i", 5);
		TRD_LOGINFO("Var = %i", 5);
		TRD_LOGWARN("Var = %i", 5);
		TRD_LOGERROR("Var = %i", 5);
		TRD_LOGFATAL("Var = %i", 5);

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