#ifndef MISS_DEFINE_H
#define MISS_DEFINE_H

#ifdef UNICODE
  #define TString std::wstring
#else
  #define TString std::string
#endif

#endif
