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
	int n, m, count;
	link joselink, current, s;
	scanf_s("%d %d", &n, &m);
	joselink = (Node *)malloc(sizeof(Node));
	current = joselink;
	joselink->next = NULL;
	joselink->data = 1;
	while (current->data < n)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = current->data + 1;
		current->next = s;
		current = current->next;

	}
	current->next = joselink;
	link r;
	count = 0;
	while (current->next != current)
	{
		count++;
		if (count == m)
		{
			r = current->next;
			current->next = r->next;
			printf("%d ", r->data);
			free(r);
			count = 0;
		}
		else
		{
			current = current->next;
		}
	}
	printf("%d\n", current->data);
	return 0;
}