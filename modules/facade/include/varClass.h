#pragma once

#include "facade.h"

namespace threemonkeybits
{
	class VarClass : public VarClassFacade
	{
	public:
		bool varVisible(int fooInt);
		bool var2Visible(float fooFloat);

		bool varNoInFacade(int fooInt);
		bool var2NoInFacade(float fooFloat);
	};
}

