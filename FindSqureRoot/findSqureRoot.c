#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = -1;
    for(long long i=1; i <= (n/i); ++i)
    {
        if(n == i*i) {
            answer = (i+1)*(i+1);
            break;
        }
        continue;
    }
    return answer;
}

int main()
{
    printf("Input a number: (0~ 50 000 000 000 000) ");
    long long num;
    scanf("%lld", &num);

    printf("sloution: %lld \n", solution(num));

    return 1;
}


