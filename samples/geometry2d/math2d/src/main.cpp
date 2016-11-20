//============================================================================
// Name        : Math2D
// Author      :
// Version     :
// Copyright   : LGPL
// Description : Version & Compile preprocessor
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Math2D"		// Crossplatform Logs
#include "logger.h"

#include "math2D.h"

using namespace threemonkeybits;

// Configuration variables:
// TODO

// Main
int main()
{
	LOGI("Welcome to the Math2D sample");
	LOGI("------------------------------------------------------------------");
	LOGI(" ");
	// Configuration
	const unsigned int executionTimeSeed = time(NULL);
	LOGI("- Generating rand numbers with seed: %d", executionTimeSeed);
	srand(executionTimeSeed);
	LOGI(" ");
	LOGI("- Random values with int and mean 5 and standard desviation 3:");	// Vector for to generate numbers
	const int value1 = math2d::randomNumber(5, 3);
	const int value2 = math2d::randomNumber(5, 3);
	const int value3 = math2d::randomNumber(5, 3);
	LOGI("Values: %d, %d, %d", value1, value2, value3);
	LOGI(" ");
	LOGI("- Random values with int and mean 10 and standard desviation 2:");
	const int value4 = math2d::randomNumber(10, 2);
	const int value5 = math2d::randomNumber(10, 2);
	const int value6 = math2d::randomNumber(10, 2);
	LOGI("Values: %d, %d, %d", value4, value5, value6);
	LOGI(" ");
	return 0;
}
