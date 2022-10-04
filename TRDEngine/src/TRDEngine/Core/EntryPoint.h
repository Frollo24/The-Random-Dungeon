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

#ifdef TRD_DIST

#ifdef _WIN32

int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ LPSTR cmdline, _In_ int cmdshow) {
	return TRDEngine::Main(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return TRDEngine::Main(argc, argv);
}

#endif // _WIN32

#else

int main(int argc, char** argv) {
	return TRDEngine::Main(argc, argv);
}

#endif // TRD_DIST