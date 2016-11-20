/*
 * dataManagement.h
 *
 *  Created on: May 31, 2015
 *      Author: piperoman
 */
#pragma once

#include <string>
#include <stdarg.h>

namespace threemonkeybits
{
	// Data management
	namespace dm
	{
		const char* toCChar(const bool &value);
		const char* toCChar(const std::string &value);
	}
}
