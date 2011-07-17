#ifndef MISS_BASE64_H
#define MISS_BASE64_H

///Base64 ¼Ó½âÃÜº¯Êı

namespace Miss
{
std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
std::string base64_decode(std::string const& encoded_string);
}

#endif
