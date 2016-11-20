//============================================================================
// Name        : Shape2D
// Author      :
// Version     :
// Copyright   : LGPL
// Description : Version & Compile preprocessor
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Shape2D"		// Crossplatform Logs
#include "logger.h"

#include "shape2D.h"
#include "square2D.h"

using namespace threemonkeybits;

// Main
int main()
{
	LOGI("Welcome to the Shape2D sample");
	LOGI("------------------------------------------------------------------");

	//Shape2D shape; // error: cannot declare variable ‘shape’ to be of abstract type

	// Create a Square
	Square2D* myDefaultSquare = new Square2D();
	Point2D point(-3.0f, -3.0f);
	float point2 = 2.0f;
	Square2D* mySquare = new Square2D(point, point2, point2);

	LOGD("I`m a: %s", myDefaultSquare->classID.c_str());
	myDefaultSquare->printLog();
	mySquare->printLog();
	LOGI("My square in valid JSON format: %s", mySquare->getJSONFormat().c_str());

	return 0;
}
