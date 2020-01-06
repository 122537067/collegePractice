#include<stdio.h>

int FibonacciPolynomial(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		
		return FibonacciPolynomial(n - 1) + FibonacciPolynomial(n - 2);
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("FibonacciPolynomial(%d)=%d",n, FibonacciPolynomial(n));
}