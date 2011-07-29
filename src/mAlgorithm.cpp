#ifndef MISS_HPP
#include <mAlgorithm.h>
#endif
#include <sstream>

namespace Miss
{
    std::vector<std::string> SplitStr(const std::string& str, char match)
    {
        std::vector<std::string> ret;
        std::string part;
        std::istringstream strm(str);
        while (getline(strm, part, match))
            ret.push_back(part);
        return ret;
    }
}

