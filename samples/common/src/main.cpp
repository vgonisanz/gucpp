//============================================================================
// Name        : commontools.cpp
// Author      : Piperoman based steveha answer in StackOverFlow
// Version     :
// Copyright   : LGPL
// Description : Version & Compile preprocessor
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Common"		// Crossplatform Logs
#include "logger.h"

// System includes
#include <stdio.h>	// printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>	// streams
#include <time.h>       // time

// Needed
#include "gucpp_config.h"	// Version Header
#include "buildTime.h"		// Preprocessor
#include "exitManagement.h"

using namespace std;
using namespace threemonkeybits;

// Declaration
void printCompilationTime();
void printExecutionTime();
void printSeeds();

// Main
int main()
{
	LOGI("Welcome to the common sample");
	LOGI("------------------------------------------------------------------");

	printCompilationTime();
	printExecutionTime();
	printSeeds();
	return 0;
}

// Functions
void printCompilationTime()
{
	LOGI("** Sample Versioning compiling time is: %s", completeVersion);
}

void printExecutionTime()
{
	const time_t t = time(NULL);   // get time now
	struct tm *timeInfo = localtime( & t );
	const int year = timeInfo->tm_year + 1900;
	const int month = timeInfo->tm_mon + 1;
	const int day = timeInfo->tm_mday;
	const int hour = timeInfo->tm_hour;
	const int min = timeInfo->tm_min;
	const int sec = timeInfo->tm_sec;

	std::ostringstream date;
	date << GUCpp_MAJOR_VERSION << "." << GUCpp_MINOR_VERSION << "." << GUCpp_PATCHLEVEL << "-V-";
	date << year << "-" << month << "-" << day << "-T-" << hour << ":" << min << ":" << sec;
	LOGI("** Sample Versioning execution time is: %s", date.str().c_str());
}

void printSeeds()
{
	LOGI(" ");
	LOGI("Setting Compilation Data seed: 	%d [Same between executions]", compilationTimeSeed);
	LOGI("Setting Exection data seed: 		%d [Diferent between executions]", executionTimeSeed);
	srand(compilationTimeSeed);
	LOGI("Values compilated Seed: %d, %d, %d, %d are always the SAME, using same seed.", rand()%10, rand()%10, rand()%10, rand()%10);
	srand(executionTimeSeed);
	LOGI("Values compilated Seed: %d, %d, %d, %d are always different, using seed generated in compilation time \n", rand()%10, rand()%10, rand()%10, rand()%10);
}
