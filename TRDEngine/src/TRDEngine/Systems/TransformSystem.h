#pragma once

#include "TRDPCH.h"
#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/Transform.h"

namespace TRDEngine {

	class TransformSystem
	{
	public:
		static void Register(const Ref<Transform>& transform);

		static void Update();

	private:
		static std::vector<Ref<Transform>> m_TransformComponents;
	};

}