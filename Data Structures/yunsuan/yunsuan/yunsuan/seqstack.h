#pragma once
#define TRUE 1
#define FALSE 0
#define Stack_Size 50

/*int栈*/
typedef struct
{
	int elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int top;          		/*用来存放栈顶元素的下标，top为-1表示空栈*/
}IntStack;

/*char栈*/
typedef struct
{
	char elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int top;          		/*用来存放栈顶元素的下标，top为-1表示空栈*/
}CharStack;

/*初始化int栈*/
void InitStack(IntStack *S)
{
	/*构造一个空栈S*/
	S->top = -1;
}
/*初始化char栈*/
void InitStack(CharStack *S)
{
	/*构造一个空栈S*/
	S->top = -1;
}
/*判栈空*/
int IsEmpty(IntStack *S) /*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top == -1 ? TRUE : FALSE);
}
/*判栈空*/
int IsEmpty(CharStack *S) /*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

/*判栈满*/
int IsFull(IntStack *S)	/*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}
/*判栈满*/
int IsFull(CharStack *S)	/*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}
/*进栈*/
int Push(CharStack *S, char x)
{
	if (S->top == Stack_Size - 1)
		return(FALSE);  /*栈已满*/
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}
/*进栈*/
int Push(IntStack *S, int x)
{
	if (S->top == Stack_Size - 1)
		return(FALSE);  /*栈已满*/
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}
/*出栈*/
int Pop(IntStack *S, int *x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中 */
	if (S->top == -1)  /*栈为空*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		S->top--;    /* 修改栈顶指针 */
		return(TRUE);
	}
}
/*出栈*/
int Pop(CharStack *S, char *x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中 */
	if (S->top == -1)  /*栈为空*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		S->top--;    /* 修改栈顶指针 */
		return(TRUE);
	}
}

/*取栈顶元素。*/
int GetTop(IntStack *S, int *x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if (S->top == -1)  /*栈为空*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		return(TRUE);
	}
}
/*取栈顶元素。*/
int GetTop(CharStack *S, char *x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if (S->top == -1)  /*栈为空*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		return(TRUE);
	}
}