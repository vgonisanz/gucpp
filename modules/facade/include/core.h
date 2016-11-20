#pragma once

#include "singleton.h"
#include "callbacks.h"

namespace threemonkeybits
{
	class Core : public Singleton<Core>, public Callbacks
	{
	public:
		// Functions
		/**
		 * \brief Description
		 * \description long description
		 * \param[in] value
		 * \return value
		 */
		bool initialize(CallbackWithPointer pCallBack);
		bool initialize(CallbackWithValist pCallBack);
		const bool isInitialized();

		// Callbacks using pointer
		// Warning managing memory
		void setCallbackWithPointer(CallbackWithPointer callback);
		int apiCallbackWithPointer(const std::string &msg, void* data);

		// Callbacks using valist, varargs functions must never receive arguments of type char, short int, or float. auto promoted to other types
		// It looks bad, it's unsafe, and it's full of technical details that have nothing to do with what you're conceptually trying to achieve.
		void setCallbackWithValist(CallbackWithValist callback);
		int apiCallbackWithValist(const std::string &msg, ...);

	protected:
		//friend class Singleton;	// Singleton friend to use constructor protected
		Core();

	private:
		bool initialize();
		bool _isInit;

		CallbackWithPointer _callbackPointer;
		CallbackWithValist _callbackValist;
	};
}

