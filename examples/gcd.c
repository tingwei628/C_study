/*
  print a b gcd and lcm
*/
#include<stdio.h>
int main() {
  int a, b, c, d, temp;
  printf("input two numbers\n");
  scanf("%d", &a);
  scanf("%d", &b);
  c = a;
  d = b;
  while((a % b)!= 0) {
   temp = a % b;
   a = b;
   b = temp;
  }
  printf("lcm: %d\n", c * d / b);
  printf("gcd: %d\n", b);
  return 0;
}
