#pragma once

namespace TRDEngine {

	class Renderer
	{
	public:
		static void Init();
		static void BeginScene();
		static void EndScene();

	private:
		static bool s_BegunScene;
	};

}