#ifndef __3MB_BASE64_
#define __3MB_BASE64_

#include <string>

namespace threemonkeybits
{
    std::string base64_encode(unsigned char const* , unsigned int len);
    std::string base64_decode(std::string const& s);
    
    void base64_test();
}

#endif // __3MB_BASE64_
