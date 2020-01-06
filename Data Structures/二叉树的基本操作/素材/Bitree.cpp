#include<iostream>
#include<stdio.h>
#include <malloc.h>
#include <conio.h>
#include<vector>
using namespace std;
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

//����������� 
void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
	if (ch == '^') *bt = NULL;
	else if (ch == '\n')return;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); //����һ���½��
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild)); //����������
		CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void Visit(BiTree root)
{
	if (root != NULL)
		printf("%c", root->data);
}

/*�������������, rootΪָ�������������ָ��*/
void  PreOrder(BiTree root)
{
	if (root != NULL) {
		//���ʸ��ڵ�  
		Visit(root);
		//�������ӽ��  
		PreOrder(root->LChild);
		//�������ӽ��  
		PreOrder(root->RChild);
	}
}

/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
void  PostOrder(BiTree root)
{
	if (root != NULL) {
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		Visit(root);
	}
}
void  InOrder(BiTree root) /* ��������������ķǵݹ��㷨 */
{
	if (root != NULL) {
		InOrder(root->LChild);
		Visit(root);
		InOrder(root->RChild);
	}
}

void PrintTree(BiTree bt, int nLayer)  /* ��������״��ӡ�Ķ����� */
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

void  LayerOrder(BiTree bt) /* ������������� */
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
	PrintTree(T, 1);
	return 0;
}