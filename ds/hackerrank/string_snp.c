#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TWO_ARRAY_LENGTH 10;
void return_string_from_function (char *s) {
  strcpy(s,  "string_you_want_to_return");
}

void int_convert_to_string(int in_int, char[] out_str) {
  sprintf(out_str, "%d", in_int);
}

void reset_char_2d_array(char t[TWO_ARRAY_LENGTH][TWO_ARRAY_LENGTH]) {
  memset(t, 0, TWO_ARRAY_LENGTH * TWO_ARRAY_LENGTH * sizeof(char));
}

void read_char_2d_array(char t[TWO_ARRAY_LENGTH][TWO_ARRAY_LENGTH], int m, int n) {
  // char[m][n]
  printf("%c", *(*(t+m)+n));
  // char[m]
  printf("%s", *(t+m));
}
void read_string_from_stdin(char[] in) {
  // store into in
  fscanf(stdin, "%s", in);
}