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

		static void DrawIndexed(uint32_t indexCount);
	};

}