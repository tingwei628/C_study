// 宣告修飾
#include <stdio.h>
#include "../index.h"

int square(int x)
{
  return x * x;
}
void printShortLong()
{
  /*
    //long longint;
    //short shortint;
    //long long longlongint;
  */
  /*
    // part 1
    printf("sizeof(int) %lu\n", sizeof(int)); // 4
    printf("sizeof(long) %lu\n", sizeof(long)); // 8
    printf("sizeof(long long) %lu\n", sizeof(long long)); // 8
    printf("sizeof(short) %lu\n", sizeof(short)); // 2
    printf("sizeof(unsigned short) %lu\n", sizeof(unsigned short)); // 2
  */

  /*
  // part 2
  // implicitly convert int to char
    unsigned char uc = 212;
    signed char sc = 127;
    char c = 97;                        // ascii 97 => a
    printf("unsigned char %d\n", ++uc); //213
    printf("signed char %d\n", ++sc);   // -128, overflow !!
    sc = 97;
    printf("signed char %c\n", c); //a
  */
  /*
  // insert numbers to array
  for (int i = 0; i < 3; i++)
    scanf("%d", &arr[i]);
  // print it out
  for (int i = 0; i < 3; i++)
    printf("%d\n", arr[i]);
  */
  /*
  double r;
  const double PI = 3.141596; // const, it cannot be modified
  int arr[3];
  //scanf("%lf", &r);
  //printf("%lf\n", r);
  printf("%d\n", square(6)); //36
  */
  int i = 1;
  int j = 2;
  const int *constIntPtr = &i;            // const int but pointer can be modified
  int *const intConstPtr = &i;            // const pointer but int can be modified
  const int *const constIntConstPrt = &i; // both int and pointer are const
  //(*constIntPtr)++;
  constIntPtr = &j;
  (*intConstPtr) += 3;
  printf("const int ptr : %d\n", (*constIntPtr));
  printf("const int ptr : %d\n", (*intConstPtr));
}