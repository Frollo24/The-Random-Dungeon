#pragma once

#include "TRDEngine/Core/Base.h"

#include <glm/glm.hpp>

namespace TRDEngine {

	class GameObject;
	class TransformBuffer;

	class Transform
	{
	public:
		Transform(const glm::mat4& transform = glm::mat4(1.0f));
		~Transform() { delete m_TransformBuffer; }

		inline void SetGameObject(GameObject* gameObject) { m_GameObject = gameObject; }

		void Translate(const glm::vec3& translation);
		void SetPosition(const glm::vec3& position);


		inline const glm::mat4& GetMatrix() { return m_Transform; }

	private:
		friend class TransformSystem;
		void Update();

	private:
		GameObject* m_GameObject = nullptr;
		glm::mat4 m_Transform;
		TransformBuffer* m_TransformBuffer = nullptr;
	};

}