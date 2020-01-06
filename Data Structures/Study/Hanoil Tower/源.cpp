#include<stdio.h>

int mount = 1;

void hanoil(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("%d :盘子从 %c 移到 %c \n",mount, a,c);  //将最大盘子从A移到C
		mount++;
	}
	else
	{
		hanoil(n - 1, a, c, b);     //n-1个盘子借助C将A移到B
		printf("%d :盘子从 %c 移到 %c \n",mount, a, c);
		mount++;
		hanoil(n - 1, b, a, c);	    //n-1个盘子借助A将B移到C
	}
}

int main()
{
	int n;
	char a='a', b='b', c='c';
	printf("盘子数量：");
	scanf_s("%d",&n);
	hanoil(n, a, b, c);
}