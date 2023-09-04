#ifndef __ares_ares_hpp__
#define __ares_ares_hpp__
 
#include <n/string.hpp>

namespace ares {
namespace bit {
constexpr unsigned char rotl(unsigned char c, unsigned int n) {
  unsigned int s = sizeof(c) * 8;
  unsigned int offset = n % s;
  return (c << offset) | (c >> (s - offset));
}

constexpr unsigned char rotr(unsigned char c, unsigned int n) {
  unsigned int s = sizeof(c) * 8;
  unsigned int offset = n % s;
  return (c >> offset) | (c << (s - offset));
}

constexpr unsigned char complement(unsigned char c) {
  return ~c;
}

} // namespace bit

constexpr n::string<char> encode(n::iterator auto input, n::iterator auto psswd) {
  n::string<char> output;

  while (input.has_next()) {
    auto tmp = psswd;

    while (tmp.has_next() and input.has_next()) {
      auto c = input.next();
      auto n = tmp.next();
      
      switch (n % 3) {
        case 0: c = bit::rotl(c, n); break;
        case 1: c = bit::rotr(c, n); break;
        case 2: c = bit::complement(c); break;
      }

      output.push(c);
    }
  }

  return output;
}


constexpr n::string<char> decode(n::iterator auto input, n::iterator auto psswd) {
  n::string<char> output;

  while (input.has_next()) {
    auto tmp = psswd;

    while (tmp.has_next() and input.has_next()) {
      auto c = input.next();
      auto n = tmp.next();
      
      switch (n % 3) {
        case 0: c = bit::rotr(c, n); break;
        case 1: c = bit::rotl(c, n); break;
        case 2: c = bit::complement(c); break;
      }

      output.push(c);
    }
  }

  return output;
}

} // namespace ares

#endif