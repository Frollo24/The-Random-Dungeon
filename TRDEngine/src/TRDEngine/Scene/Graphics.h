#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Graphics/Model.h"
#include "TRDEngine/Graphics/Material.h"

namespace TRDEngine {

	class GameObject;

	class Graphics
	{
	public:
		Graphics(const std::string& filepath);

		inline void SetGameObject(GameObject* gameObject) { m_GameObject = gameObject; }
		inline void SetColor(const Color& color) { m_Color = color; }

	private:
		friend class RenderSystem;
		void Render();
		void Update();

	private:
		GameObject* m_GameObject = nullptr;
		Color m_Color{};

		Ref<Model> m_Model = nullptr;
		Ref<VertexArray> m_VertexArray = nullptr;
		Ref<VertexBuffer> m_VertexBuffer = nullptr;
		Ref<IndexBuffer> m_IndexBuffer = nullptr;

		Ref<Material> m_Material = nullptr;
	};

}