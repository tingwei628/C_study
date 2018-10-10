#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h> // C99
#define TWO_ARRAY_LENGTH 10;
void return_string_from_function (char *s) {
  strcpy(s,  "string_you_want_to_return");
}

void int_convert_to_string(int in_int, char[] out_str) {
  sprintf(out_str, "%d", in_int);
}

// strtoimax is from inttypes.h
void string_convert_to_int(char[] in_str, int out_int) {
  out_int = strtoimax(in_str, NULL, 10); // 10 表示十進位
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

// fscanf 遇到space/NULl 會停止
void read_string_from_stdin(char[] in) {
  // store into in
  fscanf(stdin, "%s", in);
}

// get sub_string from string
void get_substring_from_string(char* s, size_t size_you_want,char* sub_string) {
  // size_you_want < sub_string length
  memcpy(sub_string, size_you_want, s);
  *(sub_string+size_you_want-1) = '\0';
}



