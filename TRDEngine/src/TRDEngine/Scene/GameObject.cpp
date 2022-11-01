#include "TRDPCH.h"
#include "GameObject.h"

#include "TRDEngine/Systems/TransformSystem.h"
#include "TRDEngine/Systems/RenderSystem.h"

namespace TRDEngine {

    GameObject::GameObject(const std::string& name)
        : m_Name(name)
    {
        m_Transform = CreateRef<Transform>();
        m_Transform->SetGameObject(this);
        TransformSystem::Register(m_Transform);
    }

    void GameObject::AddGraphics(const Ref<Graphics>& graphics)
    {
        m_Graphics = graphics;
        m_Graphics->SetGameObject(this);
        RenderSystem::Register(graphics);
    }

}