#pragma once

#include "TRDEngine/Core/Base.h"

#include <glm/glm.hpp>

namespace TRDEngine {

	class GameObject;

	class Transform
	{
	public:
		Transform(const glm::mat4& transform = glm::mat4(1.0f));

		inline void SetGameObject(GameObject* gameObject) { m_GameObject = gameObject; }

		void Translate(const glm::vec3& translation);

		void Update();

		inline const glm::mat4& GetMatrix() { return m_Transform; }

	private:
		GameObject* m_GameObject = nullptr;
		glm::mat4 m_Transform;
	};

}