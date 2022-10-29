#pragma once

#include <glm/glm.hpp>

namespace TRDEngine {

	class Camera
	{
	public:
		Camera(const glm::mat4& view, const glm::mat4& projection);

		inline const glm::mat4& GetView() const { return m_View; }
		inline void SetView(const glm::mat4& view) { m_View = view; }

		inline const glm::mat4& GetProjection() const { return m_Projection; }
		inline void SetProjection(const glm::mat4& proj) { m_Projection = proj; }

		inline const glm::mat4& GetViewProjMatrix() const { return m_ViewProjMatrix; }

	protected:
		void RecalculateViewMatrix();

	private:
		glm::mat4 m_View, m_Projection;
		glm::mat4 m_ViewProjMatrix;
	};

}