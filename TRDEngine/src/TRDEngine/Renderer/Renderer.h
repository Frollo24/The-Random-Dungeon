#pragma once

#include "TRDEngine/Renderer/VertexArray.h"
#include "TRDEngine/Renderer/IndexBuffer.h"
#include "TRDEngine/Renderer/Shader.h"
#include "TRDEngine/Renderer/Texture.h"

namespace TRDEngine {

	class Renderer
	{
	public:
		static void Init();
		static void BeginScene();
		static void EndScene();
		static void Submit(const Ref<VertexArray>& vertexArray, const Ref<IndexBuffer>& indexBuffer, const Ref<Shader>& shader);

	private:
		static bool s_BegunScene;
	};

}