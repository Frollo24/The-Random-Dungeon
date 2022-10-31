#pragma once

#include "TRDEngine/Renderer/VertexArray.h"

#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

namespace TRDEngine {

	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoord;

		bool operator==(const Vertex& other) const {
			return Position == other.Position 
				&& Normal == other.Normal 
				&& TexCoord == other.TexCoord;
		}
	};

	class Model
	{
	public:
		Model(const std::string& filepath);

		inline const Ref<VertexArray>& GetVertexArray() { return m_VertexArray; }
		inline const Ref<VertexBuffer>& GetVertexBuffer() { return m_VertexBuffer; }
		inline const Ref<IndexBuffer>& GetIndexBuffer() { return m_IndexBuffer; }

	private:
		Ref<VertexArray> m_VertexArray = nullptr;
		Ref<VertexBuffer> m_VertexBuffer = nullptr;
		Ref<IndexBuffer> m_IndexBuffer = nullptr;

		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;
	};

}

namespace std {
	template<> struct hash<TRDEngine::Vertex> {
		size_t operator()(TRDEngine::Vertex const& vertex) const {
			return (
				(hash<glm::vec3>()(vertex.Position) ^
				(hash<glm::vec3>()(vertex.Normal) << 1)) >> 1) ^
				(hash<glm::vec2>()(vertex.TexCoord) << 1);
		}
	};
}