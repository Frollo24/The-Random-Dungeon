#pragma once

#include "TRDEngine/Renderer/Shader.h"

namespace TRDEngine {

	class Material
	{
	public:
		Material(const Ref<Shader>& shader, const Color& color, uint32_t glossiness = 3);

		inline const Ref<Shader>& GetShader() { return m_Shader; }

		inline const Color& GetColor() const { return m_Color; }
		inline void SetColor(const Color& color) { m_Color = color; }

		inline const uint32_t& GetGlossiness() const { return m_Glossiness; }
		inline void SetGlossiness(const uint32_t& glossiness) { m_Glossiness = glossiness; }

		void Lerp(const Ref<Material>& startMat, const Ref<Material>& endMat, float t);

	private:
		Ref<Shader> m_Shader = nullptr;
		Color m_Color = Color();
		uint32_t m_Glossiness = 3;

		// TODO texturing
	};

}