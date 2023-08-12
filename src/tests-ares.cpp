#include <stdio.h>

constexpr unsigned char rotl(unsigned char c, unsigned int n) {
  unsigned int s = sizeof(c) * 8;
  unsigned int offset = n % s;
  return (c << offset) | (c >> (s - offset));
}

void printb(unsigned char value) {
  for (int i = sizeof(value) * 8 - 1; i >= 0; --i) {
    printf("%d", (value >> i) & 1);
  }
}

int main() {
  printb(10);
  printf("\n");
  printb(rotl(10, 1));
  printf("\n");
  printb(rotl(10, -1));
}
