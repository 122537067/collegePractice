#include<iostream>
#include<stdio.h>

int sum;
int recursion_factorial(int n)
{
	if (n > 0)
	{
		sum = n * recursion_factorial(n - 1);
		printf("%d����ֵΪ%d\n", n, sum);
		return sum;
	}

	else
	{
		return 1;
	}
}

int main()
{
	int n;
	printf("������׳�����");
	scanf_s("%d",&n);
	recursion_factorial(n);
}
