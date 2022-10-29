#include "TRDPCH.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace TRDEngine {

	Camera::Camera(const glm::mat4& view, const glm::mat4& projection)
		: m_View(view), m_Projection(projection), m_ViewProjMatrix(projection * view)
	{
		
	}

	void Camera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 5.0f));

		m_View = glm::inverse(transform);
		m_ViewProjMatrix = m_Projection * m_View;
	}

}