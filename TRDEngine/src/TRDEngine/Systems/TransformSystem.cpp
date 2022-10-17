#include "TRDPCH.h"
#include "TransformSystem.h"

namespace TRDEngine {

	std::vector<Ref<Transform>> TransformSystem::m_TransformComponents{};

	void TransformSystem::Register(const Ref<Transform>& transform)
	{
		m_TransformComponents.push_back(transform);
	}

	void TransformSystem::Update()
	{
		for (const auto& transform : m_TransformComponents)
			transform->Update();
	}

}