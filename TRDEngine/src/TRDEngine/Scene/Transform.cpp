#include "TRDPCH.h"
#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace TRDEngine {

	struct TransformBuffer { // TODO convert to transform command buffer
		glm::vec3 translation{};
	};

	static TransformBuffer s_TransformBuffer{};

	Transform::Transform(const glm::mat4& transform)
		: m_Transform(transform)
	{

	}

	void Transform::Translate(const glm::vec3& translation)
	{
		s_TransformBuffer.translation += translation;
	}

	void Transform::Update()
	{
		if (s_TransformBuffer.translation == glm::vec3(0.0f)) return;

		TRD_LOGDEBUG("Updating transform!");
		m_Transform = glm::translate(m_Transform, s_TransformBuffer.translation);
		s_TransformBuffer.translation = glm::vec3(0.0f);
	}

}