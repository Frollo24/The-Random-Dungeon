#pragma once

namespace TRDEngine {

	struct Timestep {
	public:
		Timestep(float time = 0.0f) : m_Time(time) {}

		inline operator float() { return m_Time; }
		inline operator const float&() const { return m_Time; }

		inline float AsSeconds() { return m_Time; }
		inline float AsMilliseconds() { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};

	class Time
	{
	public:
		static const Timestep& TotalTime;
		static const Timestep& DeltaTime;

	private:
		friend class Application;

	private:
		static Timestep s_TotalTime;
		static Timestep s_DeltaTime;
	};

}