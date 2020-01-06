
#include<stdio.h>
#include <malloc.h>
#include <conio.h>
typedef char DataType;
//二叉链表的结点结构定义 
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
//构造二叉链表 
void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='^') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void Visit(BiTree root)
{
	if(root!=NULL)
	 printf("%c ",root->data);
}

/*先序遍历二叉树, root为指向二叉树根结点的指针*/
void  PreOrder(BiTree root) 
{
	/*在此处补充代码*/
}

/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
void  PostOrder(BiTree root) 
{
   /*在此处补充代码*/
}
void  InOrder(BiTree root) /* 中序遍历二叉树的非递归算法 */
{
	/*在此处补充代码*/
}

void PrintTree(BiTree bt,int nLayer)  /* 按竖向树状打印的二叉树 */
{
	/*在此处补充代码*/
}

int  LayerOrder(BiTree bt) /* 层序遍历二叉树 */
{ 
	/*在此处补充代码*/
}/* LayerOrder */

int main()
{
	BiTree T;
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);
	printf("先序遍历输出序列为:");
	PreOrder(T);
    printf("\n中序遍历输出序列为:");
	InOrder(T);
	printf("\n后序遍历输出序列为:");
	PostOrder(T);
	printf("\n层序遍历输出序列为:");
	LayerOrder(T);
	printf("\n竖向打印二叉树:\n");
	PrintTree(T,1); 
	getch();
	return 0;
}
