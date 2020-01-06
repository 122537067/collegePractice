#include "seqstack.h"
#include "stdio.h"
#include <conio.h>

char oper[5][5]={ {'>','>','<','<','>'},
                  {'>','>','<','<','>'},
			      {'>','>','>','>','>'},
			      {'>','>','>','>','>'},
			      {'<','<','<','<','='}
		        };//���ȼ���ά��ֻ��5������+-*/# 
char ch,x;
int IsNum(char ch);
char Execute(char a,char op,char b);
char Compare(char topsign,char ch);
int ExpEvaluation()
/*��������ֵ�� operatsign��operatdata�ֱ�Ϊ�����ջ��������ջ�� OPSΪ���������*/
{
 char ch,topdata,topsign;
 char a,b,op,result;
 SeqStack operatdata, operatsign;
 InitStack(&operatdata);
 InitStack(&operatsign);
 Push(&operatsign,'#'); 
 printf("\nPlease input an expression(Ending with ��) :");
 ch=getchar();
 ch=getchar();
 GetTop(&operatsign,&topsign);
 while(ch!='#'||topsign!='#')   /* GetTop()ͨ������ֵ����ջ��Ԫ��*/
  {
    if(IsNum(ch)==1) //�ǲ����� 
    {  
	  Push(&operatdata,ch-'0'); 
	  ch=getchar();
	}
    else
    { 
	  
      switch(Compare(topsign,ch))//�Ƚϵ�ǰ�������Ϻ�ջ�����������ȼ� 
      {
       case '<': Push(&operatsign,ch);
                 ch=getchar();  break;

       case'>':Pop(&operatsign,&op);
 	           Pop(&operatdata,&b);
               Pop(&operatdata,&a);
               result=Execute(a,op,b); /* ��a��b����op���� */
               Push(&operatdata,result);
               break;
//     case'=': Pop(&operatsign,&x);
//	            ch=getchar(); break;
        } 
    } 
    GetTop(&operatsign,&topsign);//������ջ��Ԫ�� 
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
