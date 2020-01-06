#include "seqstack.h"
#include "stdio.h"
#include <conio.h>
//#include <iostream>
//using namespace std;
const int Maxsize = 100;//表达式的最长长度； 
char oper[7][7] = { { '>','>','<','<','<','>','>' },
					{ '>','>','<','<','<','>','>' },
					{ '>','>','>','>','<','>','>' },
					{ '>','>','>','>','<','>','>' },
					{ '<','<','<','<','<','>','>' },
					{ '>','>','>','>','>','=','>' },
					{ '<','<','<','<','<','<','=' }};
					//根据运算符号的优先级对照表初始或该二位数组 
char ch, x;
int IsNum(char ch);
int Execute(int data1, char op, int data2);
char Compare(char topsign, char ch);
int ExpEvaluation(char str[])
/*并计算其值。 operatsign和operatdata分别为运算符栈和运算数栈， OPS为运算符集合*/
{
	char ch, topdata, topsign;
	int data, data1, data2, result;//第一个数/第二个数/运算结果
	int i;
	char op;//运算符
	CharStack operatsign;  //操作符栈 
	IntStack  operatdata;  //操作数栈 
	InitStack(&operatdata);
	InitStack(&operatsign);

	Push(&operatsign, str[0]); //#进操作符栈 
	GetTop(&operatsign, &topsign);//获取当前操作符栈栈顶 
	i = 1;
	while (str[i] != '#' || topsign != '#')   /* GetTop()通过函数值返回栈顶元素*/
	{
		if (IsNum(str[i]) == 1) //如果是数字字符 ，读连续的数字字符，组成操作数 
		{
			//请在此处补充代码
			int x1 , x2 = 0;
			x1 = str[i] - '0';
			i++;
			while(IsNum(str[i]) == 1)
			{			
				x2 = x1;//传递
				x1 = str[i] - '0';//第一个数字
				x2 = x2 * 10 + x1;
				x1 = x2;//把前一位的数又传回去
				i++;
			}
			Push(&operatdata, x1);												
		}
		else
		{
			switch (Compare(topsign, str[i]))//比较当前操作符合和栈顶操作符优先级 
			{
				case '<':
				{				
					Push(&operatsign, str[i]);
					i++;
					break;					
				}

				case'>':
				{				
					if (str[i] == ')')
					{						
						GetTop(&operatsign, &topsign);
						if (topsign == '(')
						{
							Pop(&operatdata, &data);
							result = data;
							Push(&operatdata, result);
							char chu;
							Pop(&operatsign, &chu);
							i++;
							break;
						}	
						else
						{
							Pop(&operatdata, &data1);//出站第一个数					
							Pop(&operatdata, &data2);//出站第二个数
							Pop(&operatsign, &op);
							result = Execute(data2, op, data1);
							Push(&operatdata, result);
							char chu;
							Pop(&operatsign, &chu);
							i++;
							break;
						}
						break;
					}
					else
					{
						Pop(&operatdata, &data1);//出站第一个数					
						Pop(&operatdata, &data2);//出站第二个数
						Pop(&operatsign, &op);//出站运算符
						result = Execute(data2, op, data1);
						Push(&operatdata, result);					
						break;		
					}
																														
				}
			}
		}
		GetTop(&operatsign, &topsign);//操作符栈顶元素 最后不用把#出栈
	}
	GetTop(&operatdata, &result);
	return(result);
}

int main()
{
	int result;
	char str[Maxsize];
	while (1)
	{
		printf("输入算术表达式，以#开始，并以#结束：");
		scanf("%s", str);
		result = ExpEvaluation(str);
		printf("%s=%d\n", str, result);
	}

	return 0;
}
int IsNum(char ch)
{
	if (ch >= '0'&&ch <= '9')
		return 1;
	else
		return 0;
}
int  Execute(int data1, char op, int data2)
{
	switch (op)
	{
	case '+': return data1 + data2;
	case '-': return data1 - data2;
	case '*': return data1*data2;
	case '/': return data1 / data2;
	}

}

char Compare(char op1, char op2)
{
	//+-*/# 
	int i, j;
	switch (op1)
	{
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '#': i = 6; break;
	}
	switch (op2)
	{
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '#': j = 6; break;
	}
	return oper[i][j];
}