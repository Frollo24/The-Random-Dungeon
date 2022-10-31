#pragma once

#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Utils/Color.h"

namespace TRDEngine {

	class RenderCommand
	{
	public:
		static void Init();
		static void SetClearColor(const Color& color);
		static void Clear();

		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		static void DrawIndexed(uint32_t indexCount);
	};

}