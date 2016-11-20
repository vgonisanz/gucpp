#pragma once

#include "point2D.h"
#include "shape2D.h"

namespace threemonkeybits
{
	class Square2D : public Shape2D
	{
	public:
		Square2D();
		Square2D(Point2D& origin, float& width, float& height);
		~Square2D();
		const bool isSquare2D = true;
		const std::string classID = std::string("Square2D");

		void setWidth(float width);
		void setHeight(float height);
		void setOrigin(Point2D origin);

		float getArea();
		float getPerimeter();
		float getWidth();
		float getHeight();
		float getDistanceFromOrigin(Point2D point);
		Point2D getOrigin();
		Point2D getCenter();
		void printLog();
		std::string getJSONFormat();
	private:
		float _width;
		float _height;
		Point2D _origin;
	};
}
