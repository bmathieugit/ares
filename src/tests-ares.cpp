#include <ares/ares.hpp>

#include <format>
#include <iostream>

constexpr void printb(unsigned char value) {
  for (int i = sizeof(value) * 8 - 1; i >= 0; --i) {
    printf("%d", (value >> i) & 1);
  }
}

int main() {
  std::string input = "Hello World !!";
  std::string passw = "Ceci est un password";
  auto encoded = ares::encode(input, passw);

  std::string out;
  std::format_to(std::back_inserter(out), "input '{}' => encoded '{}'\n", input, encoded);
  std::string decoded = ares::decode(encoded, passw);

  std::format_to(std::back_inserter(out), "encoded '{}' => decoded '{}'\n", encoded, decoded);
  std::cout << out;
}
