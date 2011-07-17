#ifndef MISS_ALGORITHM_H
#define MISS_ALGORITHM_H

#include <cstdlib>
#include <vector>

namespace Miss
{

///大对象才使用
template <typename T>
void RandShuffleList( T& listInOut )
{
    T result;
    typename T::iterator itor;
    while (listInOut.size()>0)
    {
        int nSelected = rand()%listInOut.size();
        itor = listInOut.begin();
        while ( --nSelected >=0)
        {
            ++itor;
        }
        result.splice(result.end(),listInOut,itor);
    }
    listInOut.swap(result);
}



template <typename T,typename L>
std::vector<T> Split(const T& s,
                const L& match,
                bool removeEmpty = false)
{
    /*
    typedef  typename T::size_type (typename T::*find_t)(const T& delim,
                                                typename T::size_type offset) const;*/
    std::vector<T> result;                 // return container for tokens
    typename T::size_type start = 0,           // starting position for searches
                 skip = 1;            // positions to skip after a match
    //T::size_type ( typename T::*pfind)(const T& delim, T::size_type offset) const  = &T::find_first_of; // search algorithm for matches

    while (start != T::npos)
    {
        // get a complete range [start..end)
        typename T::size_type end = s.find(match, start);
        // null strings always match in string::find, but
        // a skip of 0 causes infinite loops. pretend that
        // no tokens were found and extract the whole string
        if (skip == 0) end = T::npos;
        T token = s.substr(start, end - start);
        if (!(removeEmpty && token.empty()))
        {
            // extract the token and add it to the result list
            result.push_back(token);
        }
        // start the next range
        if ((start = end) != T::npos) start += skip;
    }
    return result;
}

}

#endif
