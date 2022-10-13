#pragma once

#include "TRDPCH.h"
#include "TRDEngine/Core/Base.h"
#include "TRDEngine/Utils/Color.h"

#include <glm/glm.hpp>

typedef int GLint;

namespace TRDEngine {

	class Shader
	{
	public:
		enum class ShaderType {
			None, Vertex, Fragment, Count
		};

	public:
		Shader(const std::string& filepath);
		~Shader();

		void Use() const;
		void Unuse() const;

		void SetBool(const std::string& name, const bool& value);
		void SetInt(const std::string& name, const int& value);
		void SetIntArray(const std::string& name, const int*& values, uint32_t count);
		void SetFloat(const std::string& name, const float& value);
		void SetFloat2(const std::string& name, const glm::vec2& value); // TODO convert to Engine types
		void SetFloat3(const std::string& name, const glm::vec3& value);
		void SetFloat4(const std::string& name, const glm::vec4& value);
		void SetColor(const std::string& name, const Color& color);
		void SetMat3(const std::string& name, const glm::mat3& matrix);
		void SetMat4(const std::string& name, const glm::mat4& matrix);

		// virtual const std::string& GetName() const;

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<ShaderType, std::stringstream> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<ShaderType, std::stringstream>& shaderSources);

	private:
		uint32_t m_RendererID = 0;
		mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;
		GLint GetUniformLocation(const std::string& name) const;
	};

}