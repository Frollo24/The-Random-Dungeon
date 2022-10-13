#include "TRDPCH.h"
#include "BufferLayout.h"

namespace TRDEngine {

	void BufferLayout::CalculateStrideAndOffset()
	{
		uint32_t offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements) {
			element.Offset = offset;
			offset += element.Size;
			m_Stride += element.Size;
		}
	}

}
