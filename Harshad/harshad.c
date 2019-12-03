#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool solution(int x)
{
	bool answer = true;
	int num = x;
	int sum = 0;
	while (num)
	{
		sum += (num % 10);
		num /= 10;
	}
	answer = (x%sum)? false:true; 
	return answer;
}

int main()
{
	printf("Input number(1~1000): ");
	int num;
	scanf("%d", &num);

	printf("Result: %d \n", (int)solution(num));

	return 1;
}
