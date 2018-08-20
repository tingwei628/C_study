#include<stdio.h>
void no_restrict_demo(int *a, int *b) {
  *a = 3;
  *b = 4;
  printf("%d", *a + *b);
  printf("\n");
}
void restrict_demo(int *restrict a, int *restrict b){
  *a = 3;
  *b = 4;
  printf("%d", *a + *b);
  printf("\n");
}

int main(int argc, char* argv[argc+1])
{
  //printf("Hello my first cmake!\n");
  int d = 6;
  int f = 7;
  int *c = &d;
  int *e = &f;
  // no_restrict_demo(c, c);
  restrict_demo(e, e);
  return 0;
}