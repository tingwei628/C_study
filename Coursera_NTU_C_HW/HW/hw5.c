/*題目
寫一個程式解線性系統 Ax = y。其中 A 是 n 乘 n 方陣，x 及 y 都是 n 乘 1 的向量。給定 A 及 y 時求解 x。
為求簡單起見，給定的 A 一定是上三角矩陣。

void upper_solver(double *A, double *x, double *y, int n);
函式 upper_solver 的第一個參數式指向 A 的指標。注意，為了節省記憶體我們只存 A 的上三角部分，
而且存成一維陣列，請參考下方的主程式。
upper_solver 的第二個參數是指向 x 的指標。upper_solver 必須將 x 的解放在這裡。
upper_solver 的第三個參數是指向 y 的指標。
upper_solver 的第四個參數是矩陣大小 n。
我們提供了主程式，請你實作函式 upper_solver。

#include 
#define N 256

void upper_solver(double *A, double *x, double *y, int n);
int main(void)
{
int i, j;
    int n; 
    double A[N * (N + 1) / 2];
    double *aptr = A;
    double x[N];
    double y[N];
    scanf("%d", &n);
    for ( i = 0 ; i < n ; i++ )
        for ( j = i ; j < n ; j++ ) {
            scanf("%lf", aptr);
            aptr++;
        }
    for ( i = 0 ; i < n ; i++ )
        scanf("%lf", &(y[i]));
    upper_solver(A, x, y, n);

    for ( i = 0 ; i < n ; i++ )
        printf("%lf ", x[i]);

    return 0;
}
參數規範

0 < n <= 256

輸入範例
3
1.000 2.000 3.000
      2.000 1.000
            4.000
2.000
3.000
-4.000
輸出範例
1.000000 2.000000 -1.000000
*/
#include<stdio.h>
#define N 256
void upper_solver(double *A, double *x, double *y, int n);
int main(void){
 int i, j;
 int n; 
 double A[N * (N + 1) / 2];
 double *aptr = A;
 double x[N];
 double y[N];
 scanf("%d", &n);
 for ( i = 0 ; i < n ; i++ )
  for ( j = i ; j < n ; j++ ) {         
      scanf("%lf", aptr);
	 aptr++;							             }
  for ( i = 0 ; i < n ; i++ )
      scanf("%lf", &(y[i]));
      upper_solver(A, x, y, n);
  for ( i = 0 ; i < n ; i++ )
        printf("%lf ", x[i]);
  printf("\n");
return 0; 
}
void upper_solver(double *A, double *x, double *y, int n){
 double sum; 
 int i,j;
 int a,k; 
 a = (n+2)*(n-1)/2;
 for(i=n-1;i>=0;i--){
    sum=0;

  if(i==n-1){
      *(x+i)= *(y+i)/(*(A+a));  
  } 
  else { 
      /*calculate sum*/
     k = (n-i)*(n-i-1)/2; 	  
     for(j=0;j<n-i-1;j++){     
      sum+= (*(A+a-k-j)) * (*(x+n-1-j));
     } 
     *(x+i) = (*(y+i)-sum) / (*(A+a-k-n+i+1));  
  }  	
 }
}
