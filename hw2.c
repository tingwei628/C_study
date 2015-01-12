/*題目
有一輛卡車行駛在沙漠中，我們想知道它最後的位置。卡車最初 (時間為 0) 是在位置 (0, 0) 
以每小時 10 公里的速度向北移動。卡車會收到一系列依照時間戳記排序的命令，1 表示「向左轉」，
2 表示「向右轉」，3 表示「停止」。每個命令的前面有一個時間戳記，所以我們知道該命令是何時發出的。
最後一個命令一定是「停止」。我們另外還假設，這輛卡車非常靈活，所以它可以在瞬間轉彎。
以下列輸入為例。卡車在時間為 5 的時候收到一個「向左轉」的命令 1，在時間 10 收到一個「向右轉」
的命令 2，在時間 15 收到一個「停止」的命令 3。那麼最後在時間 15 的時候，卡車的位置將在 (-50, 100)。
程式只需要輸出卡車的最後位置。第一個數字是 x 坐標，第二個數字是 y 坐標。

輸入範例

5
1 
10 
2 
15 


輸出範例
請務必依照範例格式填寫，兩個數字之間空半格，否則系統無法準確判定答案是否正確。

-50 100

*/
#include<stdio.h>
 /* count 表示第幾次
    count 偶數次是 x->y
    count 奇數次是 y->x
    flag = 1 表示+x 或+y 
    flag =-1 表示-x 或-y
    cond_a =1 左轉, cond_a=2 右轉, cond_a=3 停止
    流程: 走到第n次(count=n)時, 結算第n-1的走的距離(第n-1次,flag值), 並選左轉或右轉
          其中, 左轉(cond_a=1)或右轉(cond_a=)決定flag值(第n次)
    備註: flag 值影響算走的距離的正負,x+= ,x-= , y-=, y+=   	  
	
     */ 
 int main(){
 	int x=0 ,y=0; 
   	int ta,tb=0,cond_a=1; 
   	int count=0 ;
   	int flag; /*flag=1 =>+x,+y; flag=-1 =>-x,-y*/
   	 while(cond_a!=3){
         	count++;
    		scanf("%d\n",&ta);
    		scanf("%d",&cond_a);  
      		if(count%2==0){
        		if(flag==-1) {	
	 			x-=(ta-tb)*10;
	 			switch(cond_a){ /* flag=-1 */
	  				case 1:
	     					flag=-1;
	     					break;
	  				default:     /*cond_a=2*/
	    					 flag=1;         	     
				}
      			 }		 
         		else{
	   			x+=(ta-tb)*10;
	   			switch(cond_a){ /*flag =1 */
	    				case 1: 
	      					flag=1;
	      					break;
	    				default:   /*cond_a=2*/
	      					flag=-1;         	     
				}
       			}
    		 }		  
      		else{
	   		if(count==1){
	      			y+=(ta-tb)*10;
	      			if (cond_a==1){flag=-1;}else{flag=1;}  
	   		}
	   		else{
             			if(flag==-1){
             				y-=(ta-tb)*10; 
	     				switch(cond_a){ /*flag=-1*/
	       					case 1:
	      	 					flag=1;
	         					break;
	      					default:     /*cond_a=2*/
	         					flag=-1;
	     				}
	    			}
	    			else{
              				y+=(ta-tb)*10;         
	      				switch(cond_a){
	        				case 1:
	          					flag=-1;
		  					break;
						default:   /*cond_a=2*/
	          					flag=1;
	     				}
	    			}			 
	  		}		
      		}
      tb=ta; 
 } 
   printf("%d %d\n",x,y);
   return 0;
 }
