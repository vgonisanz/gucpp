#include "fileManager.h"
#define LOG_TAG "FileManager"
#include "logger.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstring>
#include <algorithm>

// Variables
namespace threemonkeybits
{
	static bool _verbose = true;

	// Static Variables
	std::string FileManager::_baseDirectory = std::string("/");

	void FileManager::setBaseDirectory(std::string baseDirectory)
	{
		LOGD("Setting base directory %s", baseDirectory.c_str());
		_baseDirectory = baseDirectory;
	}

	std::string FileManager::absolutePathFromRelative(const std::string &fileName)
	{
		std::string absoluteFilePath;
		absoluteFilePath += _baseDirectory;
		absoluteFilePath += fileName;
		return absoluteFilePath;
	}

	void FileManager::readFile(const std::string &absoluteFileName, std::string &completeFile)
	{
		LOGD("Opening file: %s", absoluteFileName.c_str());

		// Read whole file
		std::ifstream file;
		long begin, end, size;
		file.open(absoluteFileName.c_str(), std::ios::binary);
		file.seekg(0, std::ios::beg);

		if(!file.is_open())
		{
			LOGE("Cannot open file");
			return;
		}
		completeFile.assign(    (std::istreambuf_iterator<char>(file) ),
				(std::istreambuf_iterator<char>()    ) );

		file.seekg(0, std::ios::beg);
		begin = file.tellg();
		file.seekg(0, std::ios::end);
		end = file.tellg();
		size = end - begin;
		LOGD("Processing: %ld bytes", size);
		file.close();
	}
	void FileManager::createFile(const std::string &relativeFileName, std::string &completeFile)
	{
		std::string absoluteFileName = _baseDirectory + relativeFileName;

		LOGD("Creating file: %s", absoluteFileName.c_str());

		std::ofstream os(absoluteFileName.c_str());
		if (!os)
		{
			LOGE("Cannot create file: %s", absoluteFileName.c_str());
		}
		else
		{
			os << completeFile;
		}
	}

	void FileManager::createFile(const std::string &relativeFileName, std::wstring &completeFile)
	{
		std::string absoluteFileName = _baseDirectory + relativeFileName;

		LOGD("Creating file: %s", absoluteFileName.c_str());

		std::wofstream os(absoluteFileName.c_str());
		if (!os)
		{
			LOGE("Cannot create file: %s", absoluteFileName.c_str());
		}
		else
		{
			os << completeFile;
		}
	}

	int FileManager::createRelativePathIfNoExist(const char* relativePath)
	{
		LOGD("createRelativePathIfNoExist: %s", relativePath);
		std::string internalPath = _baseDirectory;
		internalPath += "/";
		//resourcesPath += _projectPath;
		//resourcesPath += "/";

		std::string fullFolder = internalPath + std::string(relativePath);

		struct stat info;
		if( stat( fullFolder.c_str(), &info ) != 0 )
		{
			LOGD( "Cannot access %s\n", fullFolder.c_str() );
			std::string partial = std::string(relativePath);
			int result_code = createPath(0777, internalPath, partial);
			return result_code;
		}
		else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows
		{
			//LOGD( "%s is a directory\n", finalPath.c_str() );
			return -3;
		}
		else
		{
			//LOGD( "%s is no directory\n", finalPath.c_str() );
			return -4;
		}
	}
	int FileManager::createPath( mode_t mode, const std::string& rootPath, std::string& path )
	{
		struct stat st;

		for( std::string::iterator iter = path.begin() ; iter != path.end(); )
		{
			std::string::iterator newIter = std::find( iter, path.end(), '/' );
			std::string newPath = rootPath + "/" + std::string( path.begin(), newIter);

			if( stat( newPath.c_str(), &st) != 0)
			{
#ifdef _WIN32
				if( CreateDirectory( newPath.c_str(), NULL) )
#else
				if( mkdir( newPath.c_str(), mode) != 0 && errno != EEXIST )
#endif
				{
					LOGE("Cannot create folder [%s] error: %s", newPath.c_str(), strerror(errno));
					return -1;
				}
			}
			else
			{
				if( !S_ISDIR(st.st_mode) )
				{
					errno = ENOTDIR;
					LOGE("Path [%s] is not a directory", newPath.c_str());
					std:: cout << "path [" << newPath << "] not a dir " << std::endl;
					return -1;
				}
				else
				{
					LOGE("Path [%s] already exists.", newPath.c_str());
				}
			}

			iter = newIter;
			if( newIter != path.end() )
				++ iter;
		}
		return 0;
	}

	std::string FileManager::getFileName(const std::string& s)
	{
		char sep = '/';

		size_t i = s.rfind(sep, s.length());
		if (i != std::string::npos)
		{
			return(s.substr(i+1, s.length() - i));
		}
		return("");
	}

	void FileManager::test()
	{
		std::string result;
		//readFile(_libraryDirectory + "/myAudio.wav", result);
		//readFile(_libraryDirectory + "/FAQ.plist", result);
		LOGD("Result %s", result.c_str());
	}
}
