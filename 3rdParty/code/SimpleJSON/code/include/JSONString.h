#ifndef _JSONSTRING_H_
#define _JSONSTRING_H_

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>

class JSONString
{
public:
    JSONString():_jsonstring(""){};

    void startJSON();       // Only limits, no use for internal json subobjects
    void finishJSON();      // same
    void continueJSON();    // Separator between JSON objects

    void startArray();
    void finishArray();

    void addBool(std::string id, bool data);
	void addInt(std::string id, int data);
    void addUnsignedInt(std::string id, unsigned int data);
	void addFloat(std::string id, float data);
    void addString(std::string id, std::string data);
    void addArray(std::string id, std::string data);
	void addArrayData(std::string data);
	void addObject(std::string id, std::string data);
	void addObjectData(std::string data);

    std::string getString() { return _jsonstring; };
    const char* getChar() { return _jsonstring.c_str(); };

    void printString();

private:
    std::string _jsonstring;
};

#endif // END _JSONSTRING_H_
