#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// atoi() is in <stdlib.h> 
// atoi 可將字串轉成整數
// ASCII code 
// +:43 , -:45 , *:42, /:47, >:62, <:60, =:61, %:37 
// space:32, !:21
// BUG 在於所有動作要有進行下一行的動作, 不然會停住
void goto_n(char(*)[80][20], int*);
void if_n(char(*)[80][20],char(*)[20], int*, int, int*);  	
void strtok_n(char*, char[80][20], int*);
void math_n(char(*)[80][20], char(*)[20] , int*, int, int*);
void print_n(char(*)[80][20],char(*)[20], int*, int, int*); 
int main(void){

char input[40][150]; //設input字元陣列可儲存40行,每行可儲存150字元
char vars[50][20];    // variables
char vals[50][20];    // values
char deli[]="= ";  //切割字元,包括空格和等號
char deli_1[]=" "; //切割字元只有空格(space) 
char *start;       //for 第一次strtok()  
int i,j,count=0;     //  count 是總行數
                    // 第一次切出input[0](第0行)的vars和vals, 排除空格和等號
		    // 第i行分割出n個字串, 例如,total_i[2]=3,表示第2行分割出3個字串 
char *ptr[5];       // for line_dec用
int  read_line;     //while() 讀第幾行用

while(scanf(" %[^\n]",input[count]) != EOF){
 count++;  
}                 /* %[^\n]前面的空格吃掉enter鍵
                  [^\n]表示除了換行\n, 均可讀取,避免原先不能讀取字串空白(space)的麻煩 */
                      // 最後 count是總行數 
int line_dec[count];
int total_i[count];
char input_i[count][80][20]; /*input[i]分割後,input_i[i][80][20]表示第i行可儲存80個字串,
			       每個字串可儲存20個字元  */
start = &input[0][0]; //從第0行的第0字元開始 
start = strtok(start,deli);
total_i[0]=0;                  // for 切割出的vars 和vals 數目
while(start!=NULL){
 strcpy(input_i[0][total_i[0]], start); 
 total_i[0]++;   
 start =strtok(NULL,deli); 
}                            //total_i[0]是vars+vals數目和END 
input_i[0][total_i[0]-1][0]='\0';    //把END取代掉
total_i[0]=total_i[0] -1;              //total_i[0]-1 

int vals_i[total_i[0]/2]; // int vals_i 儲存 atoi(vals[])

for(i=0; i<total_i[0];i++){  // 個別儲存在vars陣列和vals陣列 
   if(i%2==0)           // 奇數項是vars , 偶數項是vals
      strcpy(vars[i/2],input_i[0][i]);
   else
      strcpy(vals[(i-1)/2],input_i[0][i]); 
}	                // (total_i[0]/2)是vars的總數 = vals總數
  
for(i=0;i<total_i[0]/2;i++){
 vals_i[i] = atoi(vals[i]);   //vals型別轉換 
}

for(i=1;i<count;i++){  	  
  ptr[0]=strstr(input[i]," = ");   // line_dec[]=0, " = "  
  ptr[1]=strstr(input[i],"IF");    // line_dec[]=1, "IF"
  ptr[2]=strstr(input[i],"PRINT"); // line_dec[]=2, "PRINT"
  ptr[3]=strstr(input[i],"GOTO");  // line_dec[]=3, "GOTO"
  ptr[4]=strstr(input[i],"STOP");  // line_dec[]=4, "STOP"
  if(ptr[0]!=NULL){
    line_dec[i]=0; 
  }  
  else if(ptr[1]!=NULL){
    line_dec[i]=1;  
  }
  else if(ptr[2]!=NULL){
   line_dec[i]=2;
  }
  else if(ptr[3]!=NULL){
   line_dec[i]=3;
  }
  else{
      line_dec[i]=4; //STOP 
  }   
}       //判斷是那種類型,並儲存在line_dec[] 

char input_temp[80][20]; 

//strtok_n(input[1],input_temp, &total_i[1]); 
//strtok_n() 分解各行, input[i]是第i幾行, input_temp是暫存空白字串, 
//total_i[i]是第i行分割數目 

for(i=1;i<count;i++){
  strtok_n(input[i],input_temp,&total_i[i]);	
 for(j=0;j<total_i[i];j++){
   strcpy(input_i[i][j],input_temp[j]); //將第j個字串strcpy的input_i[i][j]第i行,第j個空白字串 
 } //strcpy()把複製到input_i[a][b], input_i[a][b], 第a行有b個字串儲存
}  //完成所有行字串分割並儲存在input_i[i]第i行 

read_line=1; //從第一行開始讀

while(line_dec[read_line]!=4){ 
	if(line_dec[read_line]==0){
                math_n(&input_i[read_line],vars,vals_i,total_i[0]/2,&read_line);
	} 
	else if(line_dec[read_line]==1){	
              if_n(&input_i[read_line],vars,vals_i,total_i[0]/2,&read_line); 
	} 
	else if(line_dec[read_line]==2){
                print_n(&input_i[read_line],vars,vals_i,total_i[0]/2,&read_line);
	}	
	else if(line_dec[read_line]==3){
               goto_n(&input_i[read_line],&read_line); //goto_n 不用下一行,read_line會改變 
	}	
	else
                printf("Error command!\n"); 	      
 
   } // end of while()
  printf("\n");
 return 0;
}

void goto_n(char (*input_n)[80][20], int *read_line_n){
  *read_line_n= atoi(input_n[0][1]);   //GOTO某行
}//end of goto_n() 

void strtok_n(char *input_n, char input_n_x[80][20] ,int *total_x){ 
 char *start_n;      //input_n 未分割字串, input_n_x儲存分割完字串, total_x 分割字串數 
 char deli_i[]=" ";    // 切割字元
 start_n = strtok(input_n,deli_i);  
 *total_x=0;
 while(start_n !=NULL){
  strcpy(input_n_x[*total_x],start_n); 
  (*total_x)++; 
  start_n = strtok(NULL,deli_i); 
 }  
} //傳入(a)未分割字串(b)需要儲存的空字串(c)total_i[i]=0
  //回傳已分割完的陣列(b) 
  //end of strtok_i()

void math_n(char (*input_n)[80][20],char (*vars_n)[20], int *vals_n,int total_vars, int *readline_n){
                // input_n接收某行的字串, vars_n接收所有變數, vals_n所有總變數的值         
    int i;      // total_n 接收某行的字串數,total_vars 接收vals_n的總數目(=vars_n總數目)  
    int n[3];  //分別記錄input_n[0],input_n[2],input_n[4], 在vals_n[]位置
      
    //在input_n[0]中,搜索需要變數值在vals_n中的位置, 
     for(i=0;i<total_vars;i++){
       if(!strcmp(input_n[0][0],vars_n[i])){
          n[0] = i;
       } //搜尋input_n[0][0]在vars_n[]中位置, 記錄在n[0]
     }   //以此類推
       for(i=0;i<total_vars;i++){
       if(!strcmp(input_n[0][2],vars_n[i])){
          n[1] = i; 
        }
      } 
       for(i=0;i<total_vars;i++){
        if(!strcmp(input_n[0][4],vars_n[i])){
          n[2] = i; 
        }
       } 
     //比較字串,比把相對位置在vals_n[]做運算 
    if(!strcmp(input_n[0][3],"+")){ 
         vals_n[n[0]] = vals_n[n[1]]+vals_n[n[2]];
          ++*readline_n;	 
    }
    else if(!strcmp(input_n[0][3],"-")){
          vals_n[n[0]] = vals_n[n[1]]-vals_n[n[2]];   
          ++*readline_n;
    }
    else if(!strcmp(input_n[0][3],"*")){
	   vals_n[n[0]] = vals_n[n[1]]*vals_n[n[2]];   
          ++*readline_n; 
    }
    else if(!strcmp(input_n[0][3],"/")){
             vals_n[n[0]] = vals_n[n[1]]/vals_n[n[2]];   
           ++*readline_n; 
    }
    else if(!strcmp(input_n[0][3],"%")){
         vals_n[n[0]] = vals_n[n[1]]%vals_n[n[2]];   
          ++*readline_n;
    }
    else {
      ++*readline_n;
    }
  
} //end of math_n()

void if_n(char (*input_n)[80][20], char (*vars_n)[20], int *vals_n, int total_vars, int *readline_n){
                // input_n接收某行的字串, vars_n接收所有變數, vals_n所有總變數的值         
    int i;      // total_n 接收某行的字串數,total_vars 接收vals_n的總數目(=vars_n總數目)  
    int n[2];  //分別記錄input_n[1],input_n[3], 在vals_n[]位置
      
    //在input_n[0]中,搜索需要變數值在vals_n中的位置, 
     for(i=0;i<total_vars;i++){
       if(!strcmp(input_n[0][1],vars_n[i])){
          n[0] = i;
       } //搜尋input_n[0][1]在vars_n[]中位置, 記錄在n[1]
      }   //以此類推
       for(i=0;i<total_vars;i++){
        if(!strcmp(input_n[0][3],vars_n[i])){
          n[1] = i; 
        }
       } 
     if(!strcmp(input_n[0][2],">") && vals_n[n[0]]>vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]);  
      }  
     else if(!strcmp(input_n[0][2],"<") && vals_n[n[0]]<vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]);    
      } 
     else if(!strcmp(input_n[0][2],"==") && vals_n[n[0]]==vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]);        
     }
      else if(!strcmp(input_n[0][2],">=") && vals_n[n[0]]>=vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]); 
      } 
     else if(!strcmp(input_n[0][2],"<=") && vals_n[n[0]]<=vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]);
      } 
     else if(!strcmp(input_n[0][2],"!=") && vals_n[n[0]]!=vals_n[n[1]]){
         *readline_n = atoi(input_n[0][5]);
      } 
     else{
       ++*readline_n;
     }
}//end of if_n()

void print_n(char (*input_n)[80][20], char (*vars_n)[20], int *vals_n, int total_vars, int *readline_n){
                // input_n接收某行的字串, vars_n接收所有變數, vals_n所有總變數的值         
    int i;      // total_n 接收某行的字串數,total_vars 接收vals_n的總數目(=vars_n總數目)  
    int n;  //分別記錄input_n[1],在vals_n[]位置
      
    //在input_n[0]中,搜索需要變數值在vals_n中的位置, 
     for(i=0;i<total_vars;i++){
        if(!strcmp(input_n[0][1],vars_n[i])){
          n=i;
        } //搜尋input_n[0][1]在vars_n[]中位置, 記錄在n
      }   
    printf("%d ",vals_n[n]);
    ++*readline_n; 
}//end of print_n
