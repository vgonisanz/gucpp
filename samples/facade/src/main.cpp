//============================================================================
// Name        : facade.cpp
// Author      : Piperoman based steveha answer in StackOverFlow
// Version     :
// Copyright   : LGPL
// Description : Version & Compile preprocessor
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Facade"		// Crossplatform Logs
#include "logger.h"

// System includes
#include <stdio.h>	// printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>	// streams
#include <time.h>       // time

// Needed
#include "include/facade.h"	// Only include facade!!! no all the folder
// Core singleton

using namespace std;
using namespace threemonkeybits;

// Main
int main()
{
	LOGI("Welcome to the facade sample");
	LOGI("------------------------------------------------------------------");

	//LOGD("Core is: %s", );
	//FooClassFacade foo;
	//foo.
	//foo.foo2NoInFacade(1.0f);

	return 0;
}

// Functions
