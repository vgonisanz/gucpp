#pragma once

#include "facade.h"

namespace threemonkeybits
{
	class FooClass : public FooClassFacade
	{
	public:
		bool fooVisible(int fooInt);
		bool foo2Visible(float fooFloat);

		bool fooNoInFacade(int fooInt);
		bool foo2NoInFacade(float fooFloat);
	};
}

