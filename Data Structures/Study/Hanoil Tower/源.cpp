#include<stdio.h>

int mount = 1;

void hanoil(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("%d :���Ӵ� %c �Ƶ� %c \n",mount, a,c);  //��������Ӵ�A�Ƶ�C
		mount++;
	}
	else
	{
		hanoil(n - 1, a, c, b);     //n-1�����ӽ���C��A�Ƶ�B
		printf("%d :���Ӵ� %c �Ƶ� %c \n",mount, a, c);
		mount++;
		hanoil(n - 1, b, a, c);	    //n-1�����ӽ���A��B�Ƶ�C
	}
}

int main()
{
	int n;
	char a='a', b='b', c='c';
	printf("����������");
	scanf_s("%d",&n);
	hanoil(n, a, b, c);
}