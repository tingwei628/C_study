#ifndef _STRING_H
#define _STRING_H
#include <string.h>
// #include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define d 256
bool __check_hash_match(int32_t _src, int32_t _tar, int32_t _q);
void rb_rolling_hash(const char* main, char* sub);
char* _build_prefix_table(char* p);
void kmp(const char* main, char* sub);
#endif