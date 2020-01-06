#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0


typedef struct Node    /*结点类型定义*/ 
{ 
	int data;
	struct Node  * next;
}Node, *link;  /* LinkList为结构指针类型*/


int main()
{
	int n,m,count,number;//count用于报数计数，number用于出列人数计数 
	link joselink,current,s;
	//printf("输入总人数n和报数规律m：\n");
	scanf("%d %d",&n,&m);
	/*建立不带头结点的循环单链表*/
	joselink = (Node *) malloc(sizeof(Node));
	current=joselink;
	joselink->next=NULL;
	joselink->data=1;
	while(current->data < n)
	{
		 s= (Node *) malloc(sizeof(Node));
		 s->data=current->data+1;
		 current->next=s;
		 current=current->next;
		 
	}
	current->next=joselink;
	
	/*模拟报数过程*/
	/* 补充模拟报数并出圈的过程*/
	return 0;	
}
