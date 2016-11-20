#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#ifdef WIN32
#include "winindent.h" // Windows
#else
#include <dirent.h>	
#endif // WIN32

namespace threemonkeybits
{
    class FileManager
    {
    public:
        // Functions
        /**
         * \brief Initialize a writable path into private file folder
         */
        static void setBaseDirectory(std::string baseDirectory);
        static std::string getBaseDirectory();
        
        ///////////////////////////////////////////////////////
        ////////////////   Calls   ////////////////////////////
        ///////////////////////////////////////////////////////
        /**
         * \brief Create from relative file path an absolute one
         *
         * \return Absolute Path to File
         */
        static std::string absolutePathFromRelative(const std::string &fileName);
        
        /**
         * \brief Read whole file and put it into completeFile
         */
        static void readFile(const std::string &absoluteFileName, std::string &completeFile);
        
        /**
		 * \brief create a new file with data in completeFile
		 */
		static void createFile(const std::string &relativeFileName, std::string &completeFile);
		static void createFile(const std::string &relativeFileName, std::wstring &completeFile);
		/**
		 * Create all folders to a given path if no exist
		*/
		static int createRelativePathIfNoExist(const char* relativePath);
		/**
		 * Like mkdir -p
		 */
		static int createPath( mode_t mode, const std::string& rootPath, std::string& path );

		static std::string getFileName(const std::string& s);

        static void test();
        
    private:
        static std::string _baseDirectory;  // Private storage
    };
    
}	// namespace tmb
