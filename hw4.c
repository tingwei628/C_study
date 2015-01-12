#include<stdio.h>
int prize(int sp[],int fi[], int myNumber);
int main(void){
	  
	int spec[3];
	int firs[3]; 
	int myNum; 
        int i;
	int total=0;
        for(i=0;i<3;i++){ 	
	 scanf("%d",&spec[i]);
	}

         for(i=0;i<3;i++){ 	
	 scanf("%d",&firs[i]);
	}
	 while(scanf("%d",&myNum)!=-1){ 
          total+=prize(spec,firs,myNum); 
         } 
        printf("%d\n",total);
 
  	return 0;/* 輸入完後記得ctrl+d, 才能跳開while-loop*/ 
}
int prize (int sp[3], int fi[3], int myNumber){

    int money=0; 
    int i;
    int count_fi; 
    int sp_num; 
    int fi_num;
       for(i=0;i<3;i++){
         sp_num=sp[i]-myNumber;
          if(sp_num==0){
	    money+=2000000;
	  } 		      
       }
       if(money<2000000){
        for(i=0;i<3;i++){
          count_fi=0; 		
          fi_num = fi[i]-myNumber;
	   while(fi_num%10==0&&count_fi<8){
	      count_fi+=1;
	      fi_num/=10;      
           }            
          switch(count_fi){
           case 8:
             if(money<=200000){		   
              money=200000;
	     }
             break;	     
           case 7:
	     if(money<=40000){
	      money=40000;
	     }
             break;	     
	   case 6:
	     if(money<=10000){
              money=10000;
	     }
	     break; 
	   case 5:
	     if(money<=4000){
	      money=4000;
	     }
	     break;
	   case 4: 
	     if(money<=1000){  
	      money=1000; 
	     }
	     break;   
	   case 3:
	     if(money<=200){
	       money=200; 
	     }
	     break;
	   default:
             money=money;	     
	 }
	}/*end of for*/
       } /*end of if*/            
    
   return money; 
}
