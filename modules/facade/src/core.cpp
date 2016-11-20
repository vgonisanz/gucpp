/*
  Core singleton class
 */

#include "core.h"
#define LOG_TAG "Core"
#include "logger.h"


#include "callbacks.h"

namespace threemonkeybits
{
	Core::Core():
	_isInit(false)
	{
		LOGD("Creating core...");
	}

	const bool Core::isInitialized()
	{
		if(!_isInit)
		{
			LOGW("Core is not initialized!");
		}
		return _isInit;
	}

	bool Core::initialize()
	{
		if(!_isInit)
		{
			LOGV("Initializing core...");
			_isInit = true;
			LOGV("Core initialized!");
			return true;
		}
		return false;
	}

    bool Core::initialize(CallbackWithPointer pCallBack)
    {
    	setCallbackWithPointer(pCallBack);
    	return initialize();
    }

    bool Core::initialize(CallbackWithValist pCallBack)
	{
		setCallbackWithValist(pCallBack);
		return initialize();
	}

    void Core::setCallbackWithPointer(CallbackWithPointer callback)
    {
    	_callbackPointer = callback;
    }

    void Core::setCallbackWithValist(CallbackWithValist callback)
   {
    	_callbackValist = callback;
   }

    int Core::apiCallbackWithPointer(const std::string &msg, void* data)
    {
    	if(!isInitialized()) return -1;
    	LOGD("apiCallbackWithPointer received message: %s", msg.c_str());
    	return _callbackPointer(msg, data);
    }

    int Core::apiCallbackWithValist(const std::string &msg, ...)
	{
    	if(!isInitialized()) return -1;
    	LOGD("apiCallbackWithValist received message: %s", msg.c_str());
    	va_list args;
		va_start(args, msg);
		const int result = _callbackValist(msg, args);
		va_end(args);
    	return result;
	}
}
