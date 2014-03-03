#include <stdio.h>

long long fib(long long int n)
{
	long long int fibo[1000];
	int i;
	fibo[0] = 0;
	fibo[1] = 1;
	for(i = 2; i <= n; i++) 
	{
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	return fibo[n];
}

int main(int argc, char *argv[])
{
	printf("%lld\n", fib(atoll(argv[1])));
	return 0;
}
