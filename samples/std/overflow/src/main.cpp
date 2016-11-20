//============================================================================
// Name        : overflow sample main
// Author      : Piperoman & rdcelis
// Version     :
// Copyright   : LGPL
// Description : http://www.cplusplus.com/reference/limits
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Overflow"		// Crossplatform Logs
#include "logger.h"

// System includes
#include "overflow.h"
#include "dataManagement.h"

#include <typeinfo>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string> // this should be already included in <sstream>

using namespace threemonkeybits;

// Declaration
template<typename T>
void printValues();

int main()
{
	LOGI("Welcome to overflow example");
	LOGI("------------------------------------------------------------------");

	printValues<unsigned int>();
	printValues<int>();
	printValues<float>();
	printValues<double>();
	return 0;
}

template<typename T>
void printValues()
{
	const char* typeT = typeid(T).name();
	const char* typeUI = typeid(unsigned int).name();
	const char* typeI = typeid(int).name();
	const char* typeF = typeid(float).name();
	const char* typeD = typeid(double).name();

	LOGI("*** Printing: %s ***", typeT);

	T underflow = 0;
	T min  = 0;
	T medium = 0;
	T max = 0;
	T over = 0;
	T overMultiplier = 0;

	const bool checkUnderflow = overflow::add<T>(std::numeric_limits<T>::min(), -1, underflow);
	const bool checkMin = overflow::add<T>(std::numeric_limits<T>::min(), 0, min);
	const bool checkMedium = overflow::add<T>(std::numeric_limits<T>::max()/2, 0, medium);
	const bool checkMax = overflow::add<T>(std::numeric_limits<T>::max(), 0, max);
	const bool checkOverflow = overflow::add<T>(std::numeric_limits<T>::max(), 1, over);
	const bool checkOverflow2 = overflow::multiply<T>(std::numeric_limits<T>::max()/2, 3, overMultiplier);

	std::string underflowStr = std::to_string(underflow);
	std::string minStr = std::to_string(min);
	std::string mediumStr = std::to_string(medium);
	std::string maxStr = std::to_string(max);
	std::string overStr = std::to_string(over);
	std::string overMultiplierStr = std::to_string(overMultiplier);

	std::string values = "( " + underflowStr + " !< [" + minStr + ", " + mediumStr + ", " + maxStr + "] !< " + overStr + ", " + overMultiplierStr + ")";

	if(typeT == typeUI)
	{
		LOGD("unsigned int values limits: %s", values.c_str());
	}
	else if(typeT == typeI)
	{
		LOGD("Integer values limits: %s", values.c_str());
	}
	else if(typeT == typeF)
	{
		LOGD("Float values limits: %s", values.c_str());
	}
	else if(typeT == typeD)
	{
		LOGD("Double values limits: %s", values.c_str());
	}
	else
	{
		LOGW("Unknown type to print");
	}

	LOGD("Correct values add?: %s !< [%s, %s, %s] !< %s, %s",
			dm::toCChar(checkUnderflow),
			dm::toCChar(checkMin),
			dm::toCChar(checkMedium),
			dm::toCChar(checkMax),
			dm::toCChar(checkOverflow),
			dm::toCChar(checkOverflow2));
}
