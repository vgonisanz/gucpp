/*
  Template class
 */

#include "varClass.h"
#define LOG_TAG "VarClassFacade"
#include "logger.h"


namespace threemonkeybits
{
	bool VarClass::varVisible(int fooInt)
	{
		return varVisible(fooInt);
	}
	bool VarClass::var2Visible(float fooFloat)
	{
		return var2Visible(fooFloat);
	}
	bool VarClass::varNoInFacade(int fooInt)
	{
		LOGD("fooNoInFacade got: %d", fooInt);
		return true;
	}
	bool VarClass::var2NoInFacade(float fooFloat)
	{
		LOGD("foo2NoInFacade got: %f", fooFloat);
		return true;
	}
}
