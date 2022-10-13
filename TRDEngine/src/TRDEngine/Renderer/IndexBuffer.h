#pragma once

namespace TRDEngine {

	class IndexBuffer {
	public:
		IndexBuffer(uint32_t count, uint32_t* indices);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }
		inline uint32_t GetCount() const { return m_Count; }

	private:
		uint32_t m_RendererID = 0;
		uint32_t m_Count = 0;
	};

}

