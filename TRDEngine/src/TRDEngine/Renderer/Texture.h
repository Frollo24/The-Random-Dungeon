#pragma once

#include "TRDPCH.h"
#include "TRDEngine/Core/Assert.h"

typedef unsigned int GLenum;

namespace TRDEngine {

	class Texture
	{
	public:
		virtual ~Texture() = default;

		void Bind(uint16_t textureUnit) const;

	protected:
		uint32_t m_RendererID = 0;
	};

	class Texture2D : public Texture
	{
	public:
		Texture2D(uint32_t width, uint32_t height);
		Texture2D(const std::string& filepath);
		virtual ~Texture2D();

		void SetData(void* data, uint32_t size) const;

	private:
		uint32_t m_Width, m_Height;
		GLenum m_DataFormat;
	};

}