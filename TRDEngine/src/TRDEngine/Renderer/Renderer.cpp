#include "TRDPCH.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace TRDEngine {

	bool Renderer::s_BegunScene = false;

	struct RendererData {
		Ref<Texture2D> WhiteTexture;
	};

	static RendererData s_RendererData;

	void Renderer::Init()
	{
		RenderCommand::Init();
		RenderCommand::SetClearColor(Color(0.2f, 0.2f, 0.2f));

		s_RendererData.WhiteTexture = CreateRef<Texture2D>(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_RendererData.WhiteTexture->Bind(0);
		s_RendererData.WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));
	}

	void Renderer::BeginScene()
	{
		TRD_ASSERT(!s_BegunScene, "Scene already has begun! Did you forget to call Renderer::EndScene?");
		s_BegunScene = true;

		ClearFlags flags = (ClearFlags)((uint8_t)ClearFlags::Color | (uint8_t)ClearFlags::Depth);
		RenderCommand::Clear(flags);
	}

	void Renderer::EndScene()
	{
		TRD_ASSERT(s_BegunScene, "Didn't begin any scene! Did you forget to call Renderer::BeginScene?");
		s_BegunScene = false;
	}

	void Renderer::Submit(const Ref<VertexArray>& vertexArray, const Ref<IndexBuffer>& indexBuffer, const Ref<Shader>& shader)
	{
		vertexArray->Bind();
		shader->Use();
		RenderCommand::DrawIndexed(indexBuffer->GetCount());
	}

}