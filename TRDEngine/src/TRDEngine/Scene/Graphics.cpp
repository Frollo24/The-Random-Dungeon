#include "TRDPCH.h"
#include "Graphics.h"

#include "TRDEngine/Renderer/Renderer.h"
#include "TRDEngine/Scene/GameObject.h"
#include "TRDEngine/Scene/Scene.h"

namespace TRDEngine {

	Graphics::Graphics(const std::string& filepath)
	{
		m_Model = CreateRef<Model>(filepath);

		auto shader = CreateRef<Shader>("assets/shaders/BlinnPhong.glsl");
		m_Material = CreateRef<Material>(shader, Color());
	}

	void Graphics::Render()
	{
		Renderer::Submit(m_Model->GetVertexArray(), m_Model->GetIndexBuffer(), m_Material->GetShader());
	}

	void Graphics::Update()
	{
		auto& shader = m_Material->GetShader();
		auto& transform = m_GameObject->GetTransform()->GetMatrix();

		shader->SetMat4("u_Transform", transform);
		shader->SetMat4("u_ViewProj", Scene::GetActiveCamera()->GetViewProjMatrix());
		shader->SetMat4("u_Normal", glm::inverse(glm::transpose(transform)));

		shader->SetColor("u_Material.color", m_Material->GetColor());
		shader->SetInt("u_Material.texture", m_Material->GetTexture() ? 1 : 0);
		shader->SetInt("u_Material.shininess", m_Material->GetGlossiness());

		shader->SetFloat3("u_ViewPos", glm::vec3(0.0f, 0.0f, 5.0f));

	}

}