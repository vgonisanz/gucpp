/*
  Template class
 */

#include "square2D.h"
#define LOG_TAG "Square2D"
#include "logger.h"

#include <sstream>

#include "JSONString.h"
#include <cmath>

namespace threemonkeybits
{
	Square2D::Square2D():
	_width(1.0f),
	_height(1.0f)
	{

	}
	Square2D::Square2D(Point2D& origin, float& width, float& height)
	{
		_origin = origin;
		_width = width;
		_height = height;
	}

	Square2D::~Square2D()
	{

	}

	float Square2D::getArea()
	{
		_area = _width * _height;
		return _area;
	}

	float Square2D::getPerimeter()
	{
		_perimeter = 2*_width + 2*_height;
		return _perimeter;
	}

	void Square2D::setWidth(float width)
	{
		_width = width;
	}
	void Square2D::setHeight(float height)
	{
		_height = height;
	}
	void Square2D::setOrigin(Point2D origin)
	{
		_origin = origin;
	}

	float Square2D::getWidth()
	{
		return _width;
	}

	float Square2D::getHeight()
	{
		return _height;
	}

	Point2D Square2D::getOrigin()
	{
		return _origin;
	}

	Point2D Square2D::getCenter()
	{
		Point2D center = Point2D(_origin.x + _width/2, _origin.y + _height/2);
		return center;
	}

	float Square2D::getDistanceFromOrigin(Point2D point)
	{
		const float distanceOrigin = sqrt(pow(_origin.x, 2) + pow(_origin.y, 2));
		const float distancePoint = sqrt(pow(point.x, 2) + pow(point.y, 2));
		return abs(distancePoint - distanceOrigin);
	}

	void Square2D::printLog()
	{
		std::ostringstream myLog("");
		myLog << "(" << _origin.x << "," << _origin.y << ") ";	// (x0,y0)
		myLog << "--> (" << (_origin.x + _width) << "," << (_origin.y + _height) << ")";	// -->(x0+w,y0+h)
		myLog << " Center:(" << _origin.x + _width/2 << "," << _origin.y + _height/2 << ")";
		LOGI("%s", myLog.str().c_str());
	}

	std::string Square2D::getJSONFormat()
	{
		Point2D center = getCenter();

		// Codify info
		JSONString info;
		info.startJSON();
		info.addString("originx", std::to_string(_origin.x));
		info.continueJSON();
		info.addString("originy", std::to_string(_origin.y));
		info.continueJSON();
		info.addString("width", std::to_string(_width));
		info.continueJSON();
		info.addString("height", std::to_string(_height));
		info.continueJSON();
		info.addString("centerx", std::to_string(center.x));
		info.continueJSON();
		info.addString("centery", std::to_string(center.y));
		info.finishJSON();

		// Package data
		JSONString data;
		data.startJSON();
		data.addString("type", LOG_TAG);
		data.continueJSON();
		data.addArray("data", info.getString());
		data.finishJSON();

		return data.getString();
	}
}
