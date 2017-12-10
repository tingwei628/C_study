#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../index.h"

/*
  write and read from "string" to another "string"
*/
void file3()
{
  char filename[200];
  int a, b, c;

  //string printf to string
  sprintf(filename, "%d_%d_%d.txt", 2017, 12, 12);
  printf("%s\n", filename); // 2017_12_12.txt

  // string scanf from string
  //split 555,333,222 to separate numbers
  sscanf("555,333,222", "%d,%d,%d", &a, &b, &c);
  printf("a: %d, b: %d, c: %d\n", a, b, c);
}