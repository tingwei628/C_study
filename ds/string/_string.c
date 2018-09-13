#include <stdio.h>
#include "_string.h"

bool __check_hash_match(int32_t _src, int32_t _tar, int32_t _q) {
  return ((_src % _q) ==  _tar);
}
void rb_rolling_hash(const char* _main_s, char* sub) {

  size_t _main_len = strlen(_main_s);
  size_t _sub_len = strlen(sub);

  if(_main_len == 0 || _sub_len == 0 || (_main_len < _sub_len))
    return;

  size_t _hash_main_curr = 0;
  size_t _hash_sub = 0;
  size_t _diff_main_sub = _main_len - _sub_len + 1;
  int32_t q = 113;
  size_t _pow_d_sublen_mod_q = 0;
  for (size_t j = 0; j < _sub_len; j++) {
    _hash_sub += (int32_t)(*(sub + j)) * pow(d, _sub_len-j-1);
    _hash_main_curr += (int32_t)(*(_main_s + j)) * pow(d, _sub_len-j-1);
  }
  _hash_sub = _hash_sub % q;
  _pow_d_sublen_mod_q = ((size_t)pow(d, _sub_len)) % q;

  for(size_t k = 0; k < _diff_main_sub; k++) {
    if (k > 0) {
      int32_t first = (int32_t)(*(_main_s + k-1));
      int32_t last = (int32_t)(*(_main_s + k + _sub_len -1));
      _hash_main_curr = (d * _hash_main_curr - _pow_d_sublen_mod_q * first + last) % q;
    }
    bool _result = false;
    _result = __check_hash_match(_hash_main_curr, _hash_sub, q);

    if (_result) {
      int32_t base = k;
      bool _is_match = true;
      for (size_t cc = 0; cc < _sub_len; cc++) {
        if (*(_main_s+base+cc) != *(sub+cc)) {
          _is_match = false;
          break;
        }
      }
      if (_is_match)
        printf("index at: %lu\n", k);
    }
  }
}
char* _build_prefix_table(char* p) {
  
}
void kmp(const char* _main_s, char* sub) {
  size_t _main_len = strlen(_main_s);
  size_t _sub_len = strlen(sub);
  if(_main_len == 0 || _sub_len == 0 || (_main_len < _sub_len))
    return;

  
}