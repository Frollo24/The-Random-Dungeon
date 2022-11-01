#include "TRDPCH.h"
#include "Model.h"

#include <tiny_obj_loader.h>

namespace TRDEngine {

	Model::Model(const std::string& filepath)
	{
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;
		std::string warn, err;

		std::unordered_map<Vertex, uint32_t> uniqueVertices;

		auto result = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filepath.c_str());
		TRD_VERIFY(result);

		for (const auto& shape : shapes) {
			for (const auto& index : shape.mesh.indices) {
				Vertex vertex{};

				vertex.Position = {
					attrib.vertices[3 * index.vertex_index + 0],
					attrib.vertices[3 * index.vertex_index + 1],
					attrib.vertices[3 * index.vertex_index + 2]
				};

				vertex.Normal = {
					attrib.normals[3 * index.normal_index + 0],
					attrib.normals[3 * index.normal_index + 1],
					attrib.normals[3 * index.normal_index + 2]
				};

				if (attrib.texcoords.size()) {
					vertex.TexCoord = {
						attrib.texcoords[2 * index.texcoord_index + 0],
						attrib.texcoords[2 * index.texcoord_index + 1]
					};
				}

				if (uniqueVertices.count(vertex) == 0) {
					uniqueVertices[vertex] = static_cast<uint32_t>(m_Vertices.size());
					m_Vertices.push_back(vertex);
				}

				m_Indices.push_back(uniqueVertices[vertex]);
			}
		}

		m_VertexArray = CreateRef<VertexArray>();

		m_VertexBuffer = CreateRef<VertexBuffer>(m_Vertices.size() * sizeof(Vertex), m_Vertices.data());
		BufferLayout triangleBufferLayout = {
			{ShaderDataType::Float3, "a_Position"},
			{ShaderDataType::Float3, "a_Normal"},
			{ShaderDataType::Float2, "a_TexCoord"},
		};
		m_VertexBuffer->SetLayout(triangleBufferLayout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		m_IndexBuffer = CreateRef<IndexBuffer>(m_Indices.size(), m_Indices.data());
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);
	}

}