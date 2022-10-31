#include "TRDPCH.h"
#include "Transform.h"
#include "GameObject.h"

#include <glm/gtc/matrix_transform.hpp>

namespace TRDEngine {

	struct TransformCommand
	{
		virtual glm::mat4 Execute(const glm::mat4& matrix) = 0;
	};

	struct TranslateCommand : TransformCommand
	{
		TranslateCommand(glm::vec3 translation) : translation{translation} {}
		glm::vec3 translation{};

		virtual glm::mat4 Execute(const glm::mat4& matrix) override { return glm::translate(matrix, translation); };
	};

	struct ScaleCommand : TransformCommand
	{
		ScaleCommand(glm::vec3 scale) : scale{scale} {}
		glm::vec3 scale{};

		virtual glm::mat4 Execute(const glm::mat4& matrix) override { return glm::scale(matrix, scale); };
	};

	struct TransformBuffer {
		std::vector<Ref<TransformCommand>> transformCommands;

		inline void Record(const Ref<TransformCommand>& command) { transformCommands.push_back(command); };

		bool HasRecord() { return !transformCommands.empty(); }
		void Clear() { transformCommands.clear(); }

		void Flush(glm::mat4& matrix)
		{
			for (int i = 0; i < transformCommands.size(); i++)
				matrix = transformCommands[i]->Execute(matrix);

			Clear();
		}
	};

	Transform::Transform(const glm::mat4& transform)
		: m_Transform(transform), m_TransformBuffer(new TransformBuffer())
	{

	}

	void Transform::Translate(const glm::vec3& translation)
	{
		m_TransformBuffer->Record(CreateRef<TranslateCommand>(translation));
	}

	void Transform::Scale(const glm::vec3& scale)
	{
		m_TransformBuffer->Record(CreateRef<ScaleCommand>(scale));
	}

	void Transform::SetPosition(const glm::vec3& position)
	{
		m_TransformBuffer->Clear();

		m_Transform = glm::translate(glm::mat4(1.0f), position);
	}

	void Transform::Update()
	{
		if (!m_TransformBuffer->HasRecord()) return;

		TRD_LOGDEBUG("Updating transform!");
		m_TransformBuffer->Flush(m_Transform);
		m_TransformBuffer->Clear();
	}

}