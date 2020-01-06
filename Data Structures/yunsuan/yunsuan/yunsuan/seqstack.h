#pragma once
#define TRUE 1
#define FALSE 0
#define Stack_Size 50

/*intջ*/
typedef struct
{
	int elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int top;          		/*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}IntStack;

/*charջ*/
typedef struct
{
	char elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int top;          		/*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}CharStack;

/*��ʼ��intջ*/
void InitStack(IntStack *S)
{
	/*����һ����ջS*/
	S->top = -1;
}
/*��ʼ��charջ*/
void InitStack(CharStack *S)
{
	/*����һ����ջS*/
	S->top = -1;
}
/*��ջ��*/
int IsEmpty(IntStack *S) /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == -1 ? TRUE : FALSE);
}
/*��ջ��*/
int IsEmpty(CharStack *S) /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

/*��ջ��*/
int IsFull(IntStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}
/*��ջ��*/
int IsFull(CharStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}
/*��ջ*/
int Push(CharStack *S, char x)
{
	if (S->top == Stack_Size - 1)
		return(FALSE);  /*ջ����*/
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}
/*��ջ*/
int Push(IntStack *S, int x)
{
	if (S->top == Stack_Size - 1)
		return(FALSE);  /*ջ����*/
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}
/*��ջ*/
int Pop(IntStack *S, int *x)
{
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if (S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
		return(TRUE);
	}
}
/*��ջ*/
int Pop(CharStack *S, char *x)
{
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if (S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
		return(TRUE);
	}
}

/*ȡջ��Ԫ�ء�*/
int GetTop(IntStack *S, int *x)
{
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if (S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		return(TRUE);
	}
}
/*ȡջ��Ԫ�ء�*/
int GetTop(CharStack *S, char *x)
{
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if (S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		return(TRUE);
	}
}