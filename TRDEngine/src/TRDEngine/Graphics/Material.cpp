#include "TRDPCH.h"
#include "Material.h"

namespace TRDEngine {

	Material::Material(const Ref<Shader>& shader, const Color& color, uint32_t glossiness)
		: m_Shader(shader), m_Color(color), m_Glossiness(glossiness)
	{
	}

	void Material::Lerp(const Ref<Material>& startMat, const Ref<Material>& endMat, float t)
	{
		// TODO math interpolation
	}

}