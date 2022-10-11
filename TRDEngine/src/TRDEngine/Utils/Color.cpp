#include "TRDPCH.h"
#include "Color.h"

namespace TRDEngine {

	Color::Color()
		: r(1.0f), g(1.0f), b(1.0f), a(1.0f)
	{
	}

	Color::Color(float red, float green, float blue)
		: r(red), g(green), b(blue), a(1.0f)
	{
	}

	Color::Color(float red, float green, float blue, float alpha)
		: r(red), g(green), b(blue), a(alpha)
	{
	}

}