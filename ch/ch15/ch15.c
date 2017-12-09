#include <stdio.h>
#include "../index.h"

void structure()
{
  M s1 = {"Ted", 333, {12, 23}};
  M *p = &s1; // p is struct pointer
  M input;
  printf("struct %lu\n", sizeof(s1));
  // 28, why not 25? cause char(20) + char(1) + int(4); 1 is not multiple of 4, it would complement to 4
  // so, 20 + 4 + 4 = 28
  printf("s1.name %s\n", s1.name);                                          // Ted
  printf("s1.date.month: %d s1.date.day %d\n", s1.date.month, s1.date.day); // 12, 23
  printf("&(s1.name) %p\n", &(s1.name));                                    // print address of s1.name
  printf("&(s1.number) %p\n", &(s1.number));                                // print address of s1.number
  printf("p -> s1.name %s\n", p->name);                                     //Ted
  printf("p -> s1.number %d\n", p->number);                                 //333
  printf("sizeof(p): %lu\n", sizeof(p));                                    // 8 bytes
  scanf("%s", input.name);                                                  // input.name -> char[21]
  scanf("%d", &(input.number));
  p = &input;
  printf("p -> s1.name %s\n", p->name);     //
  printf("p -> s1.number %d\n", p->number); //
}