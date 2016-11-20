#pragma once

#include <string>

namespace threemonkeybits
{
	class Shape2D
	{
	public:
		Shape2D();
		virtual ~Shape2D() = 0;
		const bool isShape2D = true;
		const std::string classID = std::string("Shape2D");

		virtual float getArea() = 0;
		virtual float getPerimeter() = 0;
		virtual void printLog() = 0;

	protected:			// Children will inherit
		float _area;
		float _perimeter;

	private:

	};
}
