#include "seqstack.h"
#include "stdio.h"
#include <conio.h>
const int Maxsize=100;//���ʽ������ȣ� 
char oper[7][7]={ 

		        };//����������ŵ����ȼ����ձ��ʼ��ö�λ���� 
char ch,x;
int IsNum(char ch);
int Execute(int data1,char op,int data2);
char Compare(char topsign,char ch);
int ExpEvaluation(char str[])
/*��������ֵ�� operatsign��operatdata�ֱ�Ϊ�����ջ��������ջ�� OPSΪ���������*/
{
 char ch,topdata,topsign;
 int data,data1,data2,result; 
 int i;
 char op;
 CharStack operatsign;  //������ջ 
 IntStack  operatdata;  //������ջ 
 InitStack(&operatdata);
 InitStack(&operatsign); 
 
 Push(&operatsign,str[0]); //#��������ջ 
 GetTop(&operatsign,&topsign);//��ȡ��ǰ������ջջ�� 
 i=1; 
 while(str[i]!='#'||topsign!='#')   /* GetTop()ͨ������ֵ����ջ��Ԫ��*/
  {
    if(IsNum(str[i])==1) //����������ַ� ���������������ַ�����ɲ����� 
    { 
       //���ڴ˴�������� 
	  
	}
    else
    {  
	  
	  switch(Compare(topsign,str[i]))//�Ƚϵ�ǰ�������Ϻ�ջ�����������ȼ� 
      {
       case '<': 
        {
       	 //���ڴ˲������ 
	    } 

       case'>':	          
	    {
       	  //���ڴ˲������ 
	    } 

      } 
    } 
    GetTop(&operatsign,&topsign);//������ջ��Ԫ�� 
  }
   GetTop(&operatdata,&result);
   return(result);
} 

int main()
{
	int result;  
	char str[Maxsize]; 	
	while(1)
	{	
	  printf("�����������ʽ����#��ʼ������#������");
	  scanf("%s",str); 
      result=ExpEvaluation(str);
      printf("%s=%d\n",str,result);
	}
    
    return 0;
}
int IsNum(char ch)
{ 
  if(ch>='0'&&ch<='9')
     return 1;
  else
     return 0;
}
int  Execute(int data1,char op,int data2)
{
	switch(op)
	{
		case '+': return data1+data2; 
		case '-': return data1-data2; 
		case '*': return data1*data2; 
		case '/': return data1/data2; 			
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
		case '(': i=4; break;		
		case ')': i=5; break;
		case '#': i=6; break;;			
	}
	switch(op2)
	{   
	    case '+': j=0; break;
		case '-': j=1; break;
		case '*': j=2; break;
		case '/': j=3; break;
		case '(': j=4; break;
		case ')': j=5; break;
		case '#': j=6; break;			
	}
	return oper[i][j];	
}
