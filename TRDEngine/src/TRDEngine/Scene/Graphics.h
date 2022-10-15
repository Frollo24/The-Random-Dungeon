#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Renderer/VertexArray.h"
#include "TRDEngine/Renderer/Shader.h"

namespace TRDEngine {

	class Graphics
	{
	public:
		Graphics();

		void Render();
		void Update();

	private:
		Ref<VertexArray> m_VertexArray = nullptr;
		Ref<VertexBuffer> m_VertexBuffer = nullptr;
		Ref<IndexBuffer> m_IndexBuffer = nullptr;
		Ref<Shader> m_Shader = nullptr;
	};

}