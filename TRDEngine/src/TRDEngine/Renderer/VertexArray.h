#pragma once

#include "TRDPCH.h"
#include "TRDEngine/Core/Base.h"

#include "TRDEngine/Renderer/VertexBuffer.h"
#include "TRDEngine/Renderer/IndexBuffer.h"

namespace TRDEngine {

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();

		void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer);
		void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer);

	private:
		uint32_t m_RendererID = 0;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers{};
		Ref<IndexBuffer> m_IndexBuffer = nullptr;
	};

}