/*
 * dataManagement.cpp
 *
 *  Created on: May 31, 2015
 *      Author: piperoman
 */
#include "dataManagement.h"
#include <stdio.h>
#include <string>     // std::string, std::to_string

namespace threemonkeybits
{
	namespace dm
	{
		const char* toCChar(const bool &value)
		{
			return (value ? "True" : "False");
		}
		const char* toCChar(const std::string &value)
		{
			return value.c_str();
		}
	}
}
