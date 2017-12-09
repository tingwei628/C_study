// bit operation
#include <stdio.h>
#include "ch13.h"

// convert int to binary format
void tobinary(unsigned int i)
{
  unsigned n;
  for (n = 1 << 31; n > 0; n = n / 2)
  {
    (i & n) ? printf("1") : printf("0");
  }
  printf("\n");
}
void printbit()
{
  int a = 8;
  int b = 8;
  int aa = 1024;
  //char *s = "abc";
  char ss[10];
  printf("%x\n", a & b);
  printf("%lu, %lu\n", sizeof(a), sizeof(aa)); // 4, 4
  //printf("%lu\n", sizeof(s)); // 8bytes, cause it is 64-bit OS
  printf("%lu\n", sizeof(ss)); // 10bytes, cause 10 chars
  tobinary(a | 19);
  printf("a | 19: %d\n", a | 19);
  tobinary(1 ^ 1);  // xor,  same => 0
  tobinary(1 ^ 12); // xor, different => 1101
  tobinary(~1);     // complement
}
