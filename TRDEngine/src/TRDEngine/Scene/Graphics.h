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

		inline const Ref<Material>& GetMaterial() { return m_Material; }
		inline void SetMaterial(const Ref<Material>& material) { m_Material = material; }

	private:
		friend class RenderSystem;
		void Render();
		void Update();

	private:
		GameObject* m_GameObject = nullptr;

		Ref<Model> m_Model = nullptr;
		Ref<Material> m_Material = nullptr;
	};

}