#pragma once

namespace threemonkeybits
{
	/**
	 * \brief Singleton base
	 */
	template <typename T>
	class Singleton
    {
	protected:
		Singleton(){};										///< Private constructor
		Singleton(const Singleton<T> &) {};					///< Explicit private copy constructor. This is a forbidden operation.
		Singleton& operator=(Singleton<T> &a) {return a;};  ///< Private operator= . This is a forbidden operation.

    public:
        static T& getInstance()
        {
        	static T instance;
        	return instance;
        }
    };
}
