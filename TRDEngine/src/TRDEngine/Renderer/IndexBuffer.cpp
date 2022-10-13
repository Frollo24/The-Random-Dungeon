#include "TRDPCH.h"
#include "IndexBuffer.h"

#include <glad/glad.h>

namespace TRDEngine {

	IndexBuffer::IndexBuffer(uint32_t count, uint32_t* indices)
		: m_Count(count)
	{
		glCreateBuffers(1, &m_RendererID);
		glNamedBufferData(m_RendererID, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}