#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Renderer/BufferLayout.h"

namespace TRDEngine {

	class VertexBuffer {
	public:
		VertexBuffer(uint32_t size, const void* data);
		~VertexBuffer();

		inline const BufferLayout& GetLayout() const { return m_Layout; }
		inline void SetLayout(const BufferLayout& layout) { m_Layout = layout; }
		void UseLayout(const uint32_t& vertexArrayID);

		void SetData(uint32_t offset, uint32_t size, const void* data);

		inline uint32_t GetRendererID() const { return m_RendererID; }

	private:
		uint32_t m_RendererID = 0;
		BufferLayout m_Layout;
		uint32_t m_VertexAttribPointer = 0;
	};

}

