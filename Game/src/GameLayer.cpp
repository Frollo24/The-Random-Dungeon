#include "GameLayer.h"

using namespace TRDEngine;

static Ref<VertexArray> s_VertexArray;
static Ref<VertexBuffer> s_VertexBuffer;
static Ref<IndexBuffer> s_IndexBuffer;
static Ref<Shader> s_Shader;

GameLayer::GameLayer() : Layer("Game Layer")
{
	// TEMPORARY
	s_VertexArray = CreateRef<VertexArray>();

	float triangleVertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	s_VertexBuffer = CreateRef<VertexBuffer>(sizeof(triangleVertices), triangleVertices);
	BufferLayout triangleBufferLayout = {
		{ShaderDataType::Float3, "a_Position"},
	};
	s_VertexBuffer->SetLayout(triangleBufferLayout);
	s_VertexArray->AddVertexBuffer(s_VertexBuffer);

	unsigned int triangleIndices[3] = { 0, 1, 2 };
	s_IndexBuffer = CreateRef<IndexBuffer>(3, triangleIndices);
	s_VertexArray->SetIndexBuffer(s_IndexBuffer);

	s_Shader = CreateRef<Shader>("assets/shaders/Test.glsl");
}

void GameLayer::OnAttach()
{
	TRD_LOGDEBUG("Layer %s OnAttach", m_DebugName.c_str());
}

void GameLayer::OnDetach()
{
	TRD_LOGDEBUG("Layer %s OnDetach", m_DebugName.c_str());
}

void GameLayer::OnUpdate()
{
	if (Input::IsKeyDown(KeyCode::T))
		TRD_LOGINFO("GameLayer::Update - %f seconds", (float)Time::DeltaTime);

	Renderer::BeginScene();
	{
		s_Shader->SetColor("u_Color", Color(0.2f, 0.9f, 0.7f));
		Renderer::Submit(s_VertexArray, s_IndexBuffer, s_Shader);
	}
	Renderer::EndScene();
}

void GameLayer::OnEvent(TRDEngine::Event& e)
{
	TRD_LOGTRACE("%s", e.ToString().c_str());
}
