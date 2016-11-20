#pragma once

namespace threemonkeybits
{
	struct Point2D
	{
	public:
		float x;
		float y;
		Point2D():
			x(0.0f),
			y(0.0f)
		{

		}
		Point2D(float xIn, float yIn):
			x(xIn),
			y(yIn)
		{

		}
		void setPoint(float xIn, float yIn)
		{
			x = xIn;
			y = yIn;
		}
	};
}
