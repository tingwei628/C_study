/* 題目
寫一個程式模擬鏡子反射。給定一個房間，其寬度為 w，長度為 d。
你可以想像房間是由 w * d 個格子所組成。房間裡有許多鏡子，
而一個鏡子就放在一個房間格子中，以 45 度角或是 -45 度角放置。
鏡子是雙面，兩面都可以反射光線。房間的周圍有 2(w + d) 個窗口。
窗口的編號由 0 到 2(w + d) - 1。每一個窗口都可以向房間內部檢視。
如果我們站在窗口 0 檢視，我們將會看到窗口 8。請參考下圖。

參數規範
0 < w <= 20
0 < d <= 20
輸入格式

輸入第一行是房間的寬度 w 與長度 d。以下 d 行每一行有 w 個 0 ，1，或 2，
分別代表該位置沒有鏡子，有一面 45 度角鏡子，或是有一面 -45 度角鏡子。

輸入範例

5 4
0 1 0 0 0
0 2 0 2 0
1 0 0 1 1
0 1 1 0 0

輸出格式
輸出共有 2(w + d) 個數字，每個數字是站在該窗口向房間內檢視時所會看到的窗口編號。

輸出範例
請務必依照範例格式填寫，兩個數字之間空半格，否則系統無法準確判定答案是否正確。

8 11 5 9 6 2 4 10 0 3 7 1 14 16 12 17 13 15


*/
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
