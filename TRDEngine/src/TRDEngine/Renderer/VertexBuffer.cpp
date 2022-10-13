#include "TRDPCH.h"
#include "VertexBuffer.h"

#include <glad/glad.h>

namespace TRDEngine {

	static GLenum ShaderTypeToOpenGLType(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:    return GL_FLOAT;
			case ShaderDataType::Float2:   return GL_FLOAT;
			case ShaderDataType::Float3:   return GL_FLOAT;
			case ShaderDataType::Float4:   return GL_FLOAT;
			case ShaderDataType::Mat3:     return GL_FLOAT;
			case ShaderDataType::Mat4:     return GL_FLOAT;
			case ShaderDataType::Int:      return GL_INT;
			case ShaderDataType::Int2:     return GL_INT;
			case ShaderDataType::Int3:     return GL_INT;
			case ShaderDataType::Int4:     return GL_INT;
			case ShaderDataType::Bool:     return GL_BOOL;
		}

		return GL_NONE;
	}

	VertexBuffer::VertexBuffer(uint32_t size, const void* data)
	{
		glCreateBuffers(1, &m_RendererID);
		glNamedBufferData(m_RendererID, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void VertexBuffer::UseLayout(const uint32_t& vertexArrayID)
	{
		for (const auto& element : m_Layout)
		{
			switch (element.Type)
			{
				case ShaderDataType::Float:
				case ShaderDataType::Float2:
				case ShaderDataType::Float3:
				case ShaderDataType::Float4:
				{
					glEnableVertexArrayAttrib(vertexArrayID, m_VertexAttribPointer);
					glVertexArrayAttribBinding(vertexArrayID, m_VertexAttribPointer, 0);
					glVertexArrayAttribFormat(vertexArrayID, m_VertexAttribPointer, element.GetComponentCount(),
						ShaderTypeToOpenGLType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, element.Offset);

					m_VertexAttribPointer++;
					break;
				}
				case ShaderDataType::Int:
				case ShaderDataType::Int2:
				case ShaderDataType::Int3:
				case ShaderDataType::Int4:
				case ShaderDataType::Bool:
				{
					glEnableVertexArrayAttrib(vertexArrayID, m_VertexAttribPointer);
					glVertexArrayAttribBinding(vertexArrayID, m_VertexAttribPointer, 0);
					glVertexArrayAttribIFormat(vertexArrayID, m_VertexAttribPointer, element.GetComponentCount(),
						ShaderTypeToOpenGLType(element.Type), element.Offset);

					m_VertexAttribPointer++;
					break;
				}
				case ShaderDataType::Mat3:
				case ShaderDataType::Mat4:
				{
					uint8_t count = element.GetComponentCount();
					for (uint8_t i = 0; i < count; i++)
					{
						glEnableVertexArrayAttrib(vertexArrayID, m_VertexAttribPointer);
						glVertexArrayAttribBinding(vertexArrayID, m_VertexAttribPointer, 0);
						glVertexArrayAttribFormat(vertexArrayID, m_VertexAttribPointer, count, ShaderTypeToOpenGLType(element.Type),
							element.Normalized ? GL_TRUE : GL_FALSE, element.Offset + sizeof(float) * count * i);
						// glVertexArrayBindingDivisor(vertexArrayID, m_VertexAttribPointer, i);
						m_VertexAttribPointer++;
					}
					break;
				}
			}
		}
	}

	void VertexBuffer::SetData(uint32_t offset, uint32_t size, const void* data)
	{
	}
}