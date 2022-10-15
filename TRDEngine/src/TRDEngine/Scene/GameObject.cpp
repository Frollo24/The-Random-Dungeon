#include "TRDPCH.h"
#include "GameObject.h"

#include "TRDEngine/Systems/RenderSystem.h"

namespace TRDEngine {

    GameObject::GameObject()
    {
    }

    void GameObject::AddGraphics(const Ref<Graphics>& graphics)
    {
        m_Graphics = graphics;
        RenderSystem::Register(graphics);
    }

    void GameObject::Create()
    {
    }

    void GameObject::Update()
    {
        m_Graphics->Update();
    }

}