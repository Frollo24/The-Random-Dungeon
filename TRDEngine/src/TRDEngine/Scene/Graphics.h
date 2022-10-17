#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Renderer/VertexArray.h"
#include "TRDEngine/Renderer/Shader.h"

namespace TRDEngine {

	class GameObject;

	class Graphics
	{
	public:
		Graphics();

		inline void SetGameObject(GameObject* gameObject) { m_GameObject = gameObject; }
		inline void SetColor(const Color& color) { m_Color = color; }

		void Render();
		void Update();

	private:
		GameObject* m_GameObject;
		Color m_Color{};

		Ref<VertexArray> m_VertexArray = nullptr;
		Ref<VertexBuffer> m_VertexBuffer = nullptr;
		Ref<IndexBuffer> m_IndexBuffer = nullptr;
		Ref<Shader> m_Shader = nullptr;
	};

}