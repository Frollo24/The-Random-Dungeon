#include "TRDPCH.h"
#include "VertexArray.h"

#include <glad/glad.h>

namespace TRDEngine {

	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_RendererID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		vertexBuffer->UseLayout(m_RendererID);
		glVertexArrayVertexBuffer(m_RendererID, 0, vertexBuffer->GetRendererID(), 0, vertexBuffer->GetLayout().GetStride());
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void VertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glVertexArrayElementBuffer(m_RendererID, indexBuffer->GetRendererID());
		m_IndexBuffer = indexBuffer;
	}

}