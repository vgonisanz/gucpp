#pragma once

#include <limits>

namespace threemonkeybits
{

namespace overflow
{
	template <typename T>
	bool add(const T& lhs, const T& rhs, T& result)	// Review and do test
	{
		result = lhs + rhs;
		if (lhs >= 0 && rhs >= 0)
		{
			if (std::numeric_limits<T>::max() - lhs < rhs)
			{
				// overflow handling
				return false;
			}
		}
		else if (lhs < 0 && rhs < 0)
		{
			if (lhs <= std::numeric_limits<T>::min() - rhs)
			{
				// overflow handling
				return false;
			}
		}
		return true;
	}
	template <typename T>
	bool multiply(const T& lhs, const T& rhs, T& result)
	{
		result = lhs * rhs;
		if (lhs != 0 && result / lhs != rhs)
		{
		    // overflow handling
			return false;
		}
		return true;
	}
}
//{
	/*template <class T>
	struct overflow
	{
	public:
		static bool add(const T& lhs, const T& rhs, T& result);
	};*/
	/*class Overflow
	{
	public:


		//static bool multiply(const int& lhs, const int& rhs, int& result);
	};*/
}
