#pragma once

#include <stdarg.h>
#include <string>

namespace threemonkeybits
{
	// Message I
	typedef int (*CallbackWithPointer)(const std::string &msg, void* data);
	typedef int (*CallbackWithValist)(const std::string &msg, va_list args);

	class Callbacks
	{
	public:

		// Functions
		/**
		 * \brief Description
		 * \description long description
		 * \param[in] value
		 * \return value
		 */
		virtual int apiCallbackWithPointer(const std::string &msg, void* data) = 0;
		virtual int apiCallbackWithValist(const std::string &msg, ...) = 0;
	};
}

