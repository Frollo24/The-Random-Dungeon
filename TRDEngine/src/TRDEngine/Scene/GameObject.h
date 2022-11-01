#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Scene/Transform.h"
#include "TRDEngine/Scene/Graphics.h"

namespace TRDEngine {

	class GameObject
	{
	public:
		GameObject(const std::string& name = "GameObject");

		void AddGraphics(const Ref<Graphics>& graphics);

		inline const std::string& GetName() { return m_Name; }
		inline const Ref<Transform>& GetTransform() { return m_Transform; }
		inline const Ref<Graphics>& GetGraphics() { return m_Graphics; }

		virtual void Create() {}
		virtual void Update() {}

	private:
		std::string m_Name;

		Ref<Transform> m_Transform = nullptr;
		Ref<Graphics> m_Graphics = nullptr;
	};

}