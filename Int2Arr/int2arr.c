#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    int digit = 0;
    long long div = 1;
    while(true)
    {
        if((n/div) > 0){ 
            digit++;
            div *= 10;
        }
        else { 
            break;
        }
    }
        
    int* answer = (int*)malloc(sizeof(int)*digit);
    memset(answer, 0, sizeof(char)*digit);
    
    for (int i = 0; i<digit; ++i)
    {
        n %= div;
        div /= 10;
        answer[digit -1 -i] = n / div;
    }
    return answer;
}

int main()
{
    printf("Input a integer(from 0 to 10 000 000 000): ");
    long long num;
    scanf("%llu", &num);

    int *arr = solution(num);
    printf("[ ");
    for(int i= 0; i<_msize(arr)/sizeof(int); ++i)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");

    return 1;
}
