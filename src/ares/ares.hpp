#ifndef __ares_ares_hpp__
#define __ares_ares_hpp__

// #include <n/string.hpp>
#include <string>
#include <string_view>
#include <algorithm>

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

constexpr unsigned char complement(unsigned char c) { return ~c; }

constexpr unsigned char add(unsigned char c, unsigned char n) { return c + n; }

constexpr unsigned char minus(unsigned char c, unsigned char n) {
  return c - n;
}

constexpr unsigned char mult(unsigned char c, unsigned char n) { return c * n; }

constexpr unsigned char div(unsigned char c, unsigned char n) { return c / n; }

} // namespace bit

constexpr std::string encode(std::string_view input, std::string_view psswd) {
  std::string output;

  for (char c : input) {
    for (char n : psswd) {
      switch (n % 5) {
      case 0:
        c = bit::rotl(c, n);
        break;
      case 1:
        c = bit::rotr(c, n);
        break;
      case 2:
        c = bit::complement(c);
        break;
      case 3:
        c = bit::add(c, n);
        break;
      case 4:
        c = bit::minus(c, n);
        break;
      }
    }

    output.push_back(c);
  }

  return output;
}

constexpr std::string decode(std::string_view input, std::string_view psswd) {
  std::string output;
  std::string reversed (psswd);
  std::reverse(reversed.begin(), reversed.end());  

  for (char c : input) {
    for (char n : reversed) {
      switch (n % 5) {
      case 0:
        c = bit::rotr(c, n);
        break;
      case 1:
        c = bit::rotl(c, n);
        break;
      case 2:
        c = bit::complement(c);
        break;
      case 3:
        c = bit::minus(c, n);
        break;
      case 4:
        c = bit::add(c, n);
        break;
      }
    }

    output.push_back(c);
  }

  return output;
}

} // namespace ares

#endif