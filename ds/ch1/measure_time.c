/*
  list all combination of {a, b, c}
  basically it would be 3! = 6 (total is 3 elements)
*/
#include<stdio.h>
#include<time.h> // clock
#include<stdint.h>// for uint32_t
#include<stdlib.h>// for exit()
#include<string.h>

void measure_time()
{
  double time_spent = 0.0f;
  clock_t start_at = clock();
  clock_t end_at;
  uint32_t a;
  /*
    code block which would be measured
  */
  for(uint32_t index = 0; index < 2000000; index++)
  {
     a=index;
  }
  end_at = clock();
  time_spent = (double)(end_at - start_at) / CLOCKS_PER_SEC;
  printf("time_spent: %lf\n", time_spent);
}
void strtok_test()
{
  char r[] = "abcd";
  char *p = r;
  int c;
  printf("%c\n", (c = *p++)); // p value assign to c then p++
  printf("%c\n", c);  // a
  printf("%c\n", *p); // b
  printf("%s\n", p); // bcd
}
void string_test()
{
  //char s[100] = " naruto";
  char t[100] = "helloworld";
  char *ptr =NULL;
  char *ptr2 =NULL;
  //strcat(t, s); //hello world naruto
  ptr = strstr(t, "world"); //world
  ptr2 = strchr(t, 'o');//d, t is start position
  while(ptr2 != NULL)
  {
    printf("char: o , at postion: %ld\n", ptr2-t);
    ptr2 = strchr(ptr2+1, 'o');
  }
  ptr2 = strrchr(ptr, 'o');
  printf("char: o , at last postion: %ld\n", ptr2-t); // find last o
  //size_t pos = strcspn(t, "o"); //4 in helloworld
  size_t pos = strspn(t, "o"); //4 in helloworld
  printf("pos of world in t: %zu\n", pos);
  ptr2 = strtok(t, "o");
  while(ptr2 != NULL)
  {
    printf("ptr2 %s\n", ptr2);
    ptr2 = strtok(NULL, "o");
  }

}
void strpbrk_test()
{
  const char str1[] = "abcde2fghi3jk4l";
  const char str2[] = "fi";
  char *ret;

  ret = strpbrk(str1, str2);
  if(ret) 
  {
      printf("First matching character: %c\n", *ret);  //f
      printf("First matching character: %s\n", ret + 1); //ghi3jk4l , which pointed to ret+1
  }
}
void static_variable_in_function_test()
{
  static uint32_t a = 5;
  uint32_t b = 3;
  a++;
  b++;
  printf("a: %d\n",a);
  printf("b: %d\n",b);
  printf("&a: %p\n",&a);
  printf("&b: %p\n",&b);
  /*
    //called first time
    a: 6
    b: 4
    &a: 0x10fd7e068
    &b: 0x7fff4fe8298c
  
    //called second time
    a: 7
    b: 4
    &a: 0x10fd7e068
    &b: 0x7fff4fe8298c
  */
}
// set static to function only visiable in the same file
// static void static_function_test()
// {
//    printf("i am static function\n");
// }
void string_array_test() {
  char str[] = "abcde";
  char *str2 = (char*) calloc (10, sizeof(char));
  str2[0] = 'a';
  str2[1] = 'b';
  str2[2] = 'c';
  str2[3] = 'd';
  str2[4] = 'e';

  printf("str: %s\n", str);
  printf("str2: %s\n", str2);
  free(str2);
  str2 = NULL;
}
void string_dynamic_array_input_test(void)
{
  //size_t dynamic_length_from_input = 0;
  //printf("input a string length (number)\n");
  //scanf("%zu", &dynamic_length_from_input);
  //char *dynamic_str_from_input = (char*)malloc(sizeof(char));
  char ptr[5] = {'\0'};
  // size_t -> format : %zu
  //printf("input a string whose length below %zu\n", dynamic_length_from_input);
  //scanf("%s", dynamic_str_from_input);
  scanf("%s", ptr);
  char *dynamic_str_from_input = strdup(ptr);
  //printf("first char: %c\n", *dynamic_str_from_input);
  //printf("second char: %c\n", *(dynamic_str_from_input+1));
  //printf("your input string length: %lu\n", strlen(dynamic_str_from_input));
  //printf("your_input_dynamic_string: %s\n", dynamic_str_from_input);
  free(dynamic_str_from_input);
  dynamic_str_from_input = NULL;
}
int main(void)
{
  
  //string_test();
  //strtok_test();
  string_dynamic_array_input_test();
  //static_function_test();

 
  return 0;
}