/*題目:
寫一個程式計算統一發票獎金。統一發票收執聯是 8 位數。每一期會有三個特獎號碼及三個頭獎號碼。獎金的算法如下。

收執聯 8 位數號碼與特獎號碼相同者為特獎 200 萬元。
收執聯 8 位數號碼與頭獎號碼相同者為頭獎 20 萬元。
收執聯末 7 位數號碼與頭獎中獎號碼末 7 位相同者為二獎 4 萬元。
收執聯末 6 位數號碼與頭獎中獎號碼末 6 位相同者為三獎 1 萬元。
收執聯末 5 位數號碼與頭獎中獎號碼末 5 位相同者為四獎 4 千元。
收執聯末 4 位數號碼與頭獎中獎號碼末 4 位相同者為五獎 1 千元。
收執聯末 3 位數號碼與頭獎中獎號碼末 3 位相同者為六獎 2 百元。

範例介面

請練習使用下列函式介面計算獎金。

int prize(int specialPrizeNumbers[3], int firstPrizeNumbers[3], int myNumber);
相對應的主程式範例如下。

int main()
{
  int i;
  int specialPrizeNumbers[3];
  int firstPrizeNumbers[3];
  int myNumber;
  int totalPrize = 0;

  for (i = 0; i < 3; i++)
    scanf("%d", &(specialPrizeNumbers[i]));
  for (i = 0; i < 3; i++)
    scanf("%d", &(firstPrizeNumbers[i]));
 while (scanf("%d", &myNumber) != EOF)
    totalPrize += prize(specialPrizeNumbers, firstPrizeNumbers, myNumber);

  printf("%d\n", totalPrize);
  return 0;
}  
輸入格式

輸入前三行為特獎號碼，後三行為頭獎號碼，之後每一行為我們收集的發票收執聯號碼。程式必須處理所有的輸入直到 EOF (end of file)。

輸入範例

55138690
14764045
41175733
68787608
77978391
11071074
12378391
68787608

輸出格式
輸出為所得獎金總額。

輸出範例
204000
*/
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
