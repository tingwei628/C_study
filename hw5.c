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
