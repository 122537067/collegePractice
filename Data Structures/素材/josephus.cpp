#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0


typedef struct Node    /*������Ͷ���*/ 
{ 
	int data;
	struct Node  * next;
}Node, *link;  /* LinkListΪ�ṹָ������*/


int main()
{
	int n,m,count,number;//count���ڱ���������number���ڳ����������� 
	link joselink,current,s;
	//printf("����������n�ͱ�������m��\n");
	scanf("%d %d",&n,&m);
	/*��������ͷ����ѭ��������*/
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
	
	/*ģ�ⱨ������*/
	/* ����ģ�ⱨ������Ȧ�Ĺ���*/
	return 0;	
}
