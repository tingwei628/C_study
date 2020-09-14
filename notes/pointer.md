```c
#include <stdio.h>
#include <string.h>
void change(char *str);
void change2(char **str);
int main(void) 
{
  char cl[] = "sss";
  printf("%p\n", cl); //cl[0] itself address
  char *p = "vfd";
  printf("%p\n", p); // vfg readonly address
  printf("%p\n", &p);
  p = "jui";
  strcpy(cl, "abc");
  printf("%p\n", cl); // cl[0] itself address 
  printf("%s\n", cl);
  printf("%s\n", p);
  printf("%p\n", p); // abc readonly address
  printf("%p\n", &p); 
  /*
    cl is not changed 
    p is changed
  */

  
  char *t1 = "cde";
  printf("before change &t1 %p\n", &t1);
  printf("before change t1 %p\n", t1);
  printf("before change t1 %s\n", t1);
  change2(&t1);
  //change(t1);
  printf("after change &t1 %p\n", &t1);
  printf("after change t1 %p\n", t1);
  printf("after change t1 %s\n", t1);
  
  //char t2[4];
  //strcpy(t2, ((const char*)0x4008c0));
  //printf("t2 %s\n", t2); // abc
  return 0;
}
void change2(char **str)
{
  printf("before &str %p\n", &str);
  printf("before str %p\n", str);
  printf("before *str %p\n", *str);
  printf("before *str %s\n", *str);
  *str = "abc";
  printf("after &str %p\n", &str);
  printf("after str %p\n", str);
  printf("after *str %p\n", *str);
  printf("after *str %s\n", *str);
}
void change(char *str) 
{
  printf("before &str %p\n", &str);
  printf("before str %p\n", str);
  printf("before str %s\n", str);
  str = "abc";
  printf("after &str %p\n", &str);
  printf("after str %p\n", str);
  printf("after str %s\n", str);
}


```
