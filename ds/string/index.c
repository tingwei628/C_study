#include <stdio.h>
#include "_string.h"
int main(void) {
  const char _main_s[] = "disdadmarsasddmars";  // a m, r a, s r, m s
  char sub[] = "mars";
  //rb_rolling_hash(_main_s, sub);
  kmp(main, sub);
  return 0;
}