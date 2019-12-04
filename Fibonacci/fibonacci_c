#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    if(n == 0) { return 0; }
    else if(n == 1) { return 1; }
    else
    {
        answer = solution(n-1) + solution(n-2);
    }
    return answer;
}

int main()
{
    printf ("Input number(1~100000): ");
    int num;
    scanf("%d", &num);

    printf("result: %d \n", solution(num));
    return 1;
}

