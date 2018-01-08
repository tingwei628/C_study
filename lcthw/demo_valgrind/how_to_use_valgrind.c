// Valgrind for checking memory leak
// especially for dynamic memory allocate leak

//NOTE:
//gcc -g how_to_use_valgrind.c -o demo
// NOT "gcc -c how_to_use_valgrind.c -o demo"

//1. Run "valgrind --leak-check=full --log-file=mylog ./demo"
//2. RUn "./demo"

#include <stdio.h>

int main(int argc, char *argv[])
{
  //int a;
  //int b = 1;
  printf("okok\n");
  return 0;
}
