#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long solution(int num)
{
	long long answer = 0;
	long long t1 = 0;
	long long t2 = 1;
	for(int i = 2; i<=num; ++i)
	{
		answer = (t1 + t2) % 1234567;
		t1 = t2;
		t2 = answer;
	}
	return answer;
}

int main()
{
	printf("Input number(1~100000): ");
	int num;
	scanf("%d", &num);

	printf("Result: %d \n", (int)solution(num));

	return 1;
}
