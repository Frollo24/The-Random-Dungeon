#include "TRDPCH.h"
#include "Shader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace TRDEngine {

	static GLenum ShaderTypeToGLenum(Shader::ShaderType type)
	{
		switch (type)
		{
			case Shader::ShaderType::None:			return 0;
			case Shader::ShaderType::Vertex:		return GL_VERTEX_SHADER;
			case Shader::ShaderType::Fragment:		return GL_FRAGMENT_SHADER;

			case Shader::ShaderType::Count:
			default:
				return 0;
		}
	}

	std::string Shader::ReadFile(const std::string& filepath)
	{
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
			}
			else
			{
				TRD_LOGERROR("Could not read from file %s", filepath);
			}
		}
		else
		{
			TRD_LOGERROR("Could not open file %s", filepath);
		}

		return result;
	}

	std::unordered_map<Shader::ShaderType, std::stringstream> Shader::PreProcess(const std::string& source)
	{
		std::unordered_map<ShaderType, std::stringstream> shaderSources;
		const char* typeToken = "#shader";

		std::stringstream stream(source);
		std::string line;

		ShaderType type = ShaderType::None;
		while (getline(stream, line)) {
			if (line.find(typeToken) != std::string::npos) {
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::Vertex;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::Fragment;
			}
			else {
				shaderSources[type] << line << '\n';
			}
		}

		return shaderSources;
	}

	void Shader::Compile(const std::unordered_map<ShaderType, std::stringstream>& shaderSources)
	{
		m_RendererID = glCreateProgram();
		std::array<GLuint, (int)ShaderType::Count> glShaderIDs{};
		int shaderIndex = 0;
		for (auto& [type, stream] : shaderSources) {
			if (type == ShaderType::None) continue;

			GLenum shaderType = ShaderTypeToGLenum(type);

			GLuint shaderID = glCreateShader(shaderType);
			std::string source = stream.str();
			const char* c_source = source.c_str();
			glShaderSource(shaderID, 1, &c_source, 0);
			glCompileShader(shaderID);

			GLint isCompiled = 0;
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shaderID);

				TRD_LOGERROR("%s", infoLog.data());
				TRD_ASSERT(false, "Shader compilation failure!");
				break;
			}

			glAttachShader(m_RendererID, shaderID);
			glShaderIDs[shaderIndex++] = shaderID;
		}

		glLinkProgram(m_RendererID);

		GLint isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(m_RendererID);
			m_RendererID = 0;

			for (GLuint& id : glShaderIDs)
				glDeleteShader(id);

			TRD_LOGERROR("%s", infoLog.data());
			TRD_ASSERT(false, "Shader linking failure!");
			return;
		}

		for (GLuint& id : glShaderIDs)
			if (id != 0) glDetachShader(m_RendererID, id);
	}

    GLint Shader::GetUniformLocation(const std::string& name) const
    {
		auto locationCache = m_UniformLocationCache.find(name);
		if (locationCache != m_UniformLocationCache.end()) return locationCache->second;

		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		m_UniformLocationCache[name] = location;
		return location;
    }

	Shader::Shader(const std::string& filepath)
	{
		std::string source = ReadFile(filepath);
		auto shaderSources = PreProcess(source);
		Compile(shaderSources);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Use() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unuse() const
	{
		glUseProgram(0);
	}

	void Shader::SetBool(const std::string& name, const bool& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform1i(m_RendererID, location, (int)value);
	}

	void Shader::SetInt(const std::string& name, const int& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform1i(m_RendererID, location, value);
	}

	void Shader::SetIntArray(const std::string& name, const int*& values, uint32_t count)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform1iv(m_RendererID, location, count, values);
	}

	void Shader::SetFloat(const std::string& name, const float& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform1f(m_RendererID, location, value);
	}

	void Shader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform2f(m_RendererID, location, value.x, value.y);
	}

	void Shader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform3f(m_RendererID, location, value.x, value.y, value.z);
	}

	void Shader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform4f(m_RendererID, location, value.x, value.y, value.z, value.w);
	}

	void Shader::SetColor(const std::string& name, const Color& color)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniform4f(m_RendererID, location, color.r, color.g, color.b, color.a);
	}

	void Shader::SetMat3(const std::string& name, const glm::mat3& matrix)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniformMatrix3fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = GetUniformLocation(name);
		glProgramUniformMatrix4fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

}