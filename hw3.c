#include<stdio.h>
   /*check func is to make sure number*/
   /*pass whole a[][] with initial numbers (0~2*(w+d)-1) */
int check(int dir,int di, int wi ,int a[di][wi],int x,int y ){
   /*di=d+2, wi=w+2 */
   /*dir is direction, 
    * left is 3, 
    * right is 5, 
    * up is 6, 
    * down is 4 */
	
 while(!(x==0)&&!(y==0)&&!(x==di-1)&&!(y==wi-1)){   
 switch(dir){
   case 3:
      if (a[x][y]==0){
        dir=dir; 
      }
      else if (a[x][y]==1){ 
        dir=dir+1;
      }
      else {/*(a[x][y]==2)*/
	dir=dir+3;
      }
      break;       
   case 4: 
      if (a[x][y]==0){
        dir=dir; 
      }
      else if (a[x][y]==1){ 
        dir=dir-1;
      }
      else{ /*(a[x][y]==2)*/
	dir=dir+1;
      }
      break;  
   case 5:
      if (a[x][y]==0){
        dir=dir; 
      }
      else if (a[x][y]==1){ 
        dir=dir+1;
      }
      else{ /*(a[x][y]==2)*/
	dir=dir-1;
      }
      break;  
   case 6: 
      if (a[x][y]==0){
        dir=dir; 
      }
      else if (a[x][y]==1){ 
        dir=dir-1; 
      }
      else {/*(a[x][y]==2)*/ 
	dir=dir-3;
      }
      break;    
   default: 	   
      dir=dir; 
      break;      
 } /*end of switch*/

/* 在邊線就不能再前進了,不然會超出邊界*/

  if(dir==3){
   if(y==0){
     break; 
    }
   else{   
      y--;
   } 
  }
  else if(dir==4){
   if(x==di-1){
     break;	   
   }
   else{   
    x++;
   }
  }
  else if(dir==5){
   if(y==wi-1){
    break; 
   }
   else{   
    y++;
   }
  }
  else{ /*dir==6 */
   if(x==0){
     break; 
   }
   else{   
    x--; 
   }
  } 
 } /*end of while-loop*/

 return a[x][y];
 /*return x+y;*/
}

int main(void){
 int w,d,i,j;
 scanf("%d",&w);
 scanf("%d/n",&d);
 int arr[d+2][w+2];
 int a_1[2*(w+d)];
 arr[0][0]=arr[0][w+1]=arr[d+1][0]=arr[d+1][w+1]=0;
 for(i=1;i<=d;i++){
  for(j=1;j<=w;j++){
   scanf("%d",&arr[i][j]);  
  }
 }
 /*initialize numbers in arr[][], dir is initial */
 for(j=1;j<=w;j++){
  arr[0][j]=2*w+d-j; /* w+d~2w+d-1, dir=4 */
  arr[d+1][j]=j-1; /* 0~w-1, dir=6*/
 }
 for(i=1;i<=d;i++){
  arr[i][w+1]=w+d-i; /* w~w+d-1, dir=5 */
  arr[i][0]=2*w+d-1+i;/* 2w+d~2w+2d-1, dir=3*/ 
 
 }
/*依照順序把check出來的數字存入a_1陣列*/
for(j=1;j<=w;j++){ 
 a_1[j-1]=check(6,d+2,w+2,arr,d,j);
}
for(i=d;i>=1;i--){
 a_1[w+d-i]=check(3,d+2,w+2,arr,i,w);
}
for(j=w;j>=1;j--){
 a_1[2*w+d-j]=check(4,d+2,w+2,arr,1,j);
}
for(i=1;i<=d;i++){
 a_1[2*w+d-1+i]=check(5,d+2,w+2,arr,i,1);
}
/*把數字依序印出*/
for(j=0;j<2*(w+d);j++){
 printf("%d ",a_1[j]);
}

return 0; 
}
