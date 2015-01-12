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
