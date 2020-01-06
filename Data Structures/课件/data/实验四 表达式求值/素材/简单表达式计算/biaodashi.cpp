#include "seqstack.h"
#include "stdio.h"
#include <conio.h>

char oper[5][5]={ {'>','>','<','<','>'},
                  {'>','>','<','<','>'},
			      {'>','>','>','>','>'},
			      {'>','>','>','>','>'},
			      {'<','<','<','<','='}
		        };//优先级二维表，只有5个符号+-*/# 
char ch,x;
int IsNum(char ch);
char Execute(char a,char op,char b);
char Compare(char topsign,char ch);
int ExpEvaluation()
/*并计算其值。 operatsign和operatdata分别为运算符栈和运算数栈， OPS为运算符集合*/
{
 char ch,topdata,topsign;
 char a,b,op,result;
 SeqStack operatdata, operatsign;
 InitStack(&operatdata);
 InitStack(&operatsign);
 Push(&operatsign,'#'); 
 printf("\nPlease input an expression(Ending with ＃) :");
 ch=getchar();
 ch=getchar();
 GetTop(&operatsign,&topsign);
 while(ch!='#'||topsign!='#')   /* GetTop()通过函数值返回栈顶元素*/
  {
    if(IsNum(ch)==1) //是操作数 
    {  
	  Push(&operatdata,ch-'0'); 
	  ch=getchar();
	}
    else
    { 
	  
      switch(Compare(topsign,ch))//比较当前操作符合和栈顶操作符优先级 
      {
       case '<': Push(&operatsign,ch);
                 ch=getchar();  break;

       case'>':Pop(&operatsign,&op);
 	           Pop(&operatdata,&b);
               Pop(&operatdata,&a);
               result=Execute(a,op,b); /* 对a和b进行op运算 */
               Push(&operatdata,result);
               break;
//     case'=': Pop(&operatsign,&x);
//	            ch=getchar(); break;
        } 
    } 
    GetTop(&operatsign,&topsign);//操作符栈顶元素 
  }
   GetTop(&operatdata,&result);
   return((int)result);
} 

int main()
{
	int result;   
    result=ExpEvaluation();
    printf("\n%d",result);
    return 0;
}
int IsNum(char ch)
{ 
  if(ch>='0'&&ch<='9')
     return 1;
  else
     return 0;
}
char Execute(char a,char op,char b)
{
	switch(op)
	{
		case '+': return (char)((int)a+ (int)b); 
		case '-': return (char)((int)a- (int)b); 
		case '*': return (char)((int)a* (int)b); 
		case '/': return (char)((int)a/ (int)b); 
			
	}
	
}

char Compare(char op1,char op2)
{
	//+-*/# 
	int i,j;
	switch(op1)
	{
		case '+': i=0; break;
		case '-': i=1; break;
		case '*': i=2; break;
		case '/': i=3; break;
		case '#': i=4; break;			
	}
	switch(op2)
	{   
	    case '+': j=0; break;
		case '-': j=1; break;
		case '*': j=2; break;
		case '/': j=3; break;
		case '#': j=4; break;			
	}
	return oper[i][j];	
}
