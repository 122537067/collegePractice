
#include<stdio.h>
#include <malloc.h>
#include <conio.h>
typedef char DataType;
//��������Ľ��ṹ���� 
typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;
typedef BiTree StackElementType;
typedef BiTree QueueElementType;
#include"stack.h" 
#include"queue.h" 
//����������� 
void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='^') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //����������
        CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void Visit(BiTree root)
{
	if(root!=NULL)
	 printf("%c ",root->data);
}

/*�������������, rootΪָ�������������ָ��*/
void  PreOrder(BiTree root) 
{
	/*�ڴ˴��������*/
}

/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
void  PostOrder(BiTree root) 
{
   /*�ڴ˴��������*/
}
void  InOrder(BiTree root) /* ��������������ķǵݹ��㷨 */
{
	/*�ڴ˴��������*/
}

void PrintTree(BiTree bt,int nLayer)  /* ��������״��ӡ�Ķ����� */
{
	/*�ڴ˴��������*/
}

int  LayerOrder(BiTree bt) /* ������������� */
{ 
	/*�ڴ˴��������*/
}/* LayerOrder */

int main()
{
	BiTree T;
	printf("����չ����������н���������������������:\n");
    CreateBiTree(&T);
	printf("��������������Ϊ:");
	PreOrder(T);
    printf("\n��������������Ϊ:");
	InOrder(T);
	printf("\n��������������Ϊ:");
	PostOrder(T);
	printf("\n��������������Ϊ:");
	LayerOrder(T);
	printf("\n�����ӡ������:\n");
	PrintTree(T,1); 
	getch();
	return 0;
}
