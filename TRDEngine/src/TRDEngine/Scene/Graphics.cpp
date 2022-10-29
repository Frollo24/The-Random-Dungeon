#include "TRDPCH.h"
#include "Graphics.h"

#include "TRDEngine/Renderer/Renderer.h"
#include "TRDEngine/Scene/GameObject.h"
#include "TRDEngine/Scene/Scene.h"

namespace TRDEngine {

	Graphics::Graphics()
	{
		// TEMPORARY - TODO convert to serialized loading
		m_VertexArray = CreateRef<VertexArray>();

		float triangleVertices[3 * 3] = {
			-1.5f, -1.5f, 0.0f,
			 1.5f, -1.5f, 0.0f,
			 0.0f,  1.5f, 0.0f
		};

		m_VertexBuffer = CreateRef<VertexBuffer>(sizeof(triangleVertices), triangleVertices);
		BufferLayout triangleBufferLayout = {
			{ShaderDataType::Float3, "a_Position"},
		};
		m_VertexBuffer->SetLayout(triangleBufferLayout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		unsigned int triangleIndices[3] = { 0, 1, 2 };
		m_IndexBuffer = CreateRef<IndexBuffer>(3, triangleIndices);
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		m_Shader = CreateRef<Shader>("assets/shaders/Test.glsl");
	}

	void Graphics::Render()
	{
		Renderer::Submit(m_VertexArray, m_IndexBuffer, m_Shader);
	}

	void Graphics::Update()
	{
		m_Shader->SetColor("u_Color", m_Color);
		m_Shader->SetMat4("u_Transform", m_GameObject->GetTransform()->GetMatrix());
		m_Shader->SetMat4("u_ViewProj", Scene::GetActiveCamera()->GetViewProjMatrix());
	}

}