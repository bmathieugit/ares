#include <ares/ares.hpp>

#include <n/io.hpp>


constexpr void printb(unsigned char value) {
  for (int i = sizeof(value) * 8 - 1; i >= 0; --i) {
    printf("%d", (value >> i) & 1);
  }
}

int main() {
  n::string<char> input = n::str("Hello World !!");
  n::string<char> passw = n::str("password");
  n::string<char> encoded = ares::encode(input.iter(), passw.iter());

  n::printf("input '$' => encoded '$'\n", input, encoded);

  n::string<char> decoded = ares::decode(encoded.iter(), passw.iter());

  n::printf("encoded '$' => decoded '$'\n", encoded, decoded);
}
