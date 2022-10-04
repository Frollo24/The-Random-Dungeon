#include "TRDPCH.h"
#include "Time.h"

namespace TRDEngine {

	const Timestep& Time::TotalTime = s_TotalTime;
	const Timestep& Time::DeltaTime = s_DeltaTime;

	Timestep Time::s_TotalTime = Timestep();
	Timestep Time::s_DeltaTime = Timestep();

}