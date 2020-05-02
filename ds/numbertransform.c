/*
 進位制轉換
 12345 (10進位) => 30071 (8進位)
*/
#include <stdio.h>
#include <math.h>
int main() {
  int num1, num2, num3, i = 1, r, sum = 0, tsum, rt;
  scanf("%d", &num1); // 原進位制
  scanf("%d", &num2); // 幾位數
  while(i <= num2) {
    scanf("%d", &r);
    sum = sum + r * pow(num1, num2 - i);
    i++;
  }
  scanf("%d", &num3); // 新進位制
  i = 0;
  tsum = sum;
  while(tsum > 0) { // 取得最大次方
    r = tsum % num3;
    tsum = tsum / num3;
    i++;
  }
  while (i > 0) { // 依序相除
    r = pow(num3, i - 1);
    rt = sum / r;
    sum = sum % r;
    printf("%d\n", rt); // 從大到小印出 位數
    i--;
  }
  return 0;
}
