// Recursion
#include <stdio.h>
#include "ch14.h"
// use recursion to count str len

/*
  source is a pointer
*/
int countstrlen(char *source)
{
  //empty
  if (*source == '\0')
    return 0;

  // total length
  return countstrlen(source + 1) + 1;
}
void recurrsion()
{
  char a[13] = "abceeee";
  printf("strlen a : %d\n", countstrlen(a)); // 7
}