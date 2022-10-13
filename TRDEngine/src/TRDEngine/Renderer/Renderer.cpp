#include "TRDPCH.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace TRDEngine {

	bool Renderer::s_BegunScene = false;

	void Renderer::Init()
	{
		RenderCommand::Init();
		RenderCommand::SetClearColor(Color(0.7f, 0.2f, 0.9f));
	}

	void Renderer::BeginScene()
	{
		TRD_ASSERT(!s_BegunScene, "Scene already has begun! Did you forget to call Renderer::EndScene?");
		s_BegunScene = true;

		RenderCommand::Clear();
	}

	void Renderer::EndScene()
	{
		TRD_ASSERT(s_BegunScene, "Didn't begin any scene! Did you forget to call Renderer::BeginScene?");
		s_BegunScene = false;
	}

	void Renderer::Submit(const Ref<VertexArray>& vertexArray, const Ref<IndexBuffer>& indexBuffer, const Ref<Shader>& shader)
	{
		vertexArray->Bind();
		indexBuffer->Bind();
		shader->Use();
		RenderCommand::DrawIndexed(indexBuffer->GetCount());
	}

}