#include<iostream>
#include<stdio.h>
#include <malloc.h>
#include <conio.h>
#include<vector>
using namespace std;
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

//构造二叉链表 
void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
	if (ch == '^') *bt = NULL;
	else if (ch == '\n')return;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild)); //生成左子树
		CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void Visit(BiTree root)
{
	if (root != NULL)
		printf("%c", root->data);
}

/*先序遍历二叉树, root为指向二叉树根结点的指针*/
void  PreOrder(BiTree root)
{
	if (root != NULL) {
		//访问根节点  
		Visit(root);
		//访问左子结点  
		PreOrder(root->LChild);
		//访问右子结点  
		PreOrder(root->RChild);
	}
}

/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
void  PostOrder(BiTree root)
{
	if (root != NULL) {
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		Visit(root);
	}
}
void  InOrder(BiTree root) /* 中序遍历二叉树的非递归算法 */
{
	if (root != NULL) {
		InOrder(root->LChild);
		Visit(root);
		InOrder(root->RChild);
	}
}

void PrintTree(BiTree bt, int nLayer)  /* 按竖向树状打印的二叉树 */
{
	int i;
	if (bt == NULL)
		return;
	PrintTree(bt->RChild, nLayer + 3);
	for (i = 0; i<nLayer; i++)
		printf("  ");
	printf("%c\n", (bt)->data);
	PrintTree(bt->LChild, nLayer + 3);
}

void  LayerOrder(BiTree bt) /* 层序遍历二叉树 */
{
	if (bt == NULL)
		return;
	vector<Node*> vec;
	vec.push_back(bt);
	int cur = 0;
	int last = 1;

	while (cur < vec.size()) {
		last = vec.size();

		while (cur < last) {
			cout << vec[cur]->data;

			if (vec[cur]->LChild != NULL)
				vec.push_back(vec[cur]->LChild);
			if (vec[cur]->RChild != NULL)
				vec.push_back(vec[cur]->RChild);

			++cur;
		}
	}
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
	PrintTree(T, 1);
	return 0;
}