#pragma once

namespace threemonkeybits
{
	class FooClassFacade
	{
	public:
		FooClassFacade() {};
		virtual ~FooClassFacade();
		virtual bool fooVisible(int fooInt) = 0;
		virtual bool foo2Visible(float fooFloat) = 0;
	};

	class VarClassFacade
	{
	public:
		VarClassFacade() {};
		virtual ~VarClassFacade();
		virtual bool varVisible(int fooInt) = 0;
		virtual bool var2Visible(float fooFloat) = 0;
	};
}

