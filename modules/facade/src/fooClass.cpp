/*
  Template class
 */

#include "fooClass.h"
#define LOG_TAG "FooClassFacade"
#include "logger.h"


namespace threemonkeybits
{
	bool FooClass::fooVisible(int fooInt)
	{
		return fooVisible(fooInt);
	}
	bool FooClass::foo2Visible(float fooFloat)
	{
		return foo2Visible(fooFloat);
	}
	bool FooClass::fooNoInFacade(int fooInt)
	{
		LOGD("fooNoInFacade got: %d", fooInt);
		return true;
	}
	bool FooClass::foo2NoInFacade(float fooFloat)
	{
		LOGD("foo2NoInFacade got: %f", fooFloat);
		return true;
	}
}
