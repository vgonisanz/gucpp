/*
  Template class
 */

#include "shape2D.h"
#define LOG_TAG "Shape2D"
#include "logger.h"

namespace threemonkeybits
{
	Shape2D::Shape2D():
	_area(0.0f),
	_perimeter(0.0f)
	{

	}

	Shape2D::~Shape2D()
	{

	}

	float Shape2D::getArea()
	{
		return _area;
	}

	float Shape2D::getPerimeter()
	{
		return _perimeter;
	}

	void Shape2D::printLog()
	{
		LOGD("Shape2D");
	}
}
