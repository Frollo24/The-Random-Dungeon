#pragma once

#include "TRDEngine/Renderer/Shader.h"

namespace TRDEngine {

	class Material
	{
	public:
		Material(const Ref<Shader>& shader, const Color& color, uint32_t glossiness = 3);

		inline const Ref<Shader>& GetShader() { return m_Shader; }

		void Lerp(const Ref<Material>& startMat, const Ref<Material>& endMat, float t);

	private:
		Ref<Shader> m_Shader = nullptr;
		Color m_Color = Color();
		uint32_t m_Glossiness = 3;

		// TODO texturing
	};

}