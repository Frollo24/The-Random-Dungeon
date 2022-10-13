#pragma once

// Core elements
#include "TRDEngine/Core/Application.h"
#include "TRDEngine/Core/Assert.h"
#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Core/Layer.h"
#include "TRDEngine/Core/Log.h"
#include "TRDEngine/Core/Memory.h"
#include "TRDEngine/Core/Time.h"

// Input polling
#include "TRDEngine/Core/Input.h"
#include "TRDEngine/Core/KeyCode.h"
#include "TRDEngine/Core/MouseCode.h"

// Debug elements
#include "TRDEngine/Debug/Debug.h"

// Event system
#include "TRDEngine/Events/Event.h"
#include "TRDEngine/Events/ApplicationEvent.h"
#include "TRDEngine/Events/KeyEvent.h"
#include "TRDEngine/Events/WindowEvent.h"

// Renderer
#include "TRDEngine/Renderer/Renderer.h"
#include "TRDEngine/Renderer/RenderCommand.h"
#include "TRDEngine/Renderer/GraphicsContext.h"
#include "TRDEngine/Renderer/VertexArray.h"
#include "TRDEngine/Renderer/VertexBuffer.h"
#include "TRDEngine/Renderer/IndexBuffer.h"
#include "TRDEngine/Renderer/Shader.h"

// Window system
#include "TRDEngine/Window/WindowSystem.h"
#include "TRDEngine/Window/Window.h"

// Utils
#include "TRDEngine/Utils/Color.h"

#ifdef TRD_ENTRY_POINT
// Entry Point
#include "TRDEngine/Core/EntryPoint.h"
#endif // TRD_ENTRY_POINT
