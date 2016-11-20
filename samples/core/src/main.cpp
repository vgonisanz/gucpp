//============================================================================
// Name        : core.cpp
// Author      :
// Version     :
// Copyright   : LGPL
// Description : Version & Compile preprocessor
//============================================================================

#include "gucpp_config.h"						// Version Header
#define LOG_TAG	"Sample-Core"		// Crossplatform Logs
#include "logger.h"

#include "core.h"
#include "dataManagement.h"

using namespace threemonkeybits;

const std::string message1 = std::string("Message1");
const std::string message2 = std::string("Message2");
const std::string message3 = std::string("Message3");

struct message2Data
{
	int myInt;
	float myFloat;
};

// Functions declaration
int callbackWithPointerSample(const std::string &msg, void* data);
int callbackWithValistSample(const std::string &msg, va_list args);

// Main
int main()
{
	LOGI("Welcome to the core sample");
	LOGI("------------------------------------------------------------------");

	/*
	const char * testInit = dm::toCChar(Core::getInstance().isInitialized());
	LOGD("Core default: %s", testInit);
	Core::getInstance().initialize(callbackWithPointerSample);
	Core::getInstance().initialize(callbackWithValistSample);
	LOGD("Core now is initialized: %s ", dm::toCChar(Core::getInstance().isInitialized()));

	// Send message 1 using callback with pointer without data
	Core::getInstance().apiCallbackWithPointer(message1, NULL);

	// Send message 2 using callback with pointer without and with struct
	message2Data data2;
	data2.myInt = 7;
	data2.myFloat = 5.2f;
	Core::getInstance().apiCallbackWithPointer(message2, NULL);
	Core::getInstance().apiCallbackWithPointer(message2, &data2);

	// Send message 1 without data
	Core::getInstance().apiCallbackWithValist(message1);
	const int myInt = 8;
	const double myDouble = 6.2f;
	Core::getInstance().apiCallbackWithValist(message2, myInt, myDouble);
	*/
	return 0;
}

int callbackWithPointerSample(const std::string &msg, void* data)
{
	LOGD("callbackWithPointerSample with message: %s", msg.c_str());
	if(!msg.compare(message1))
	{
		LOGD("No data to parse");
	}
	else if(!msg.compare(message2))
	{
		if(data == NULL)
		{
			// NO DATA
			LOGE("Message 2 without pointer to data");
			return -1;
		}
		message2Data* dataReceived = (message2Data*)data;
		LOGD("Int is: %d", dataReceived->myInt);
		LOGD("Float is: %f", dataReceived->myFloat);
	}
	return 0;
}

int callbackWithValistSample(const std::string &msg, va_list args)
{
	LOGD("callbackWithValistSample with message: %s", msg.c_str());
	if(!msg.compare(message1))
	{
		LOGD("No data to parse");
	}
	else if(!msg.compare(message2))
	{
		const int myInt = va_arg(args, int);
		const double myDouble = va_arg(args, double);
		LOGD("Int is: %d", myInt);
		LOGD("Double is: %f", myDouble);
	}
}
