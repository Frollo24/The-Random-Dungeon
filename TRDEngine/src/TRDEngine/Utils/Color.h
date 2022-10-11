#pragma once

namespace TRDEngine {

	struct Color
	{
	public:
		float r, g, b, a;

		Color();
		Color(float red, float green, float blue);
		Color(float red, float green, float blue, float alpha);
	};

}