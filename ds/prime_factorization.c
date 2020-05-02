/*
 質因數分解
 // input
 n = 120

 // output  2^2 * 3^1 * 5*1 = 120
 2
 3
 3
 1
 5
 1
*/
#include <stdio.h>
#include <math.h>
// define bool type
typedef enum { false, true } bool;
int main() {
  int n, num = 2, i = 0;
  int n1, j = 2;
  bool isPrime = true; // is prime number
  scanf("%d", &n);
  while(n > 1) {
    while(n % num == 0) {
      n = n / num;
      i++;
    }
    n1 = sqrt(num);
    while(n1 >= j) {
      if (num % j == 0) {
        isPrime = false;
        break;
      }
      isPrime = true;
      j++;
    }
    if (isPrime && i > 0) {
      printf("%d\n", num);
      printf("%d\n", i); 
    }
    i = 0;
    j = 2;
    num++;
  }
  return 0;
}
