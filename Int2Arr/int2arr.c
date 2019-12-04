#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    int digit = 0;
    long long div = 1;
    while(n/div)
    {
        digit++;
        div *= 10;
    }
    int* answer = (int*)malloc(sizeof(int)*digit);
    memset(answer, 0, sizeof(char)*digit);
    for (int i = 0; i<digit; ++i)
    {
        answer[i] = n % 10;
        n /= 10;
    }
    return answer;
}

int* solution2(long long n) {
    long long num = n;
    int pos = 0;
    while(num)
    {
        num /=10;
        pos++;
    }
    int* answer = (int*)malloc(sizeof(int)*pos);
    num = n;
    pos = 0;
    while(num)
    {
        answer[pos++] = num % 10;       
        num /= 10;
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
    free(arr);

    int* arr2 = solution2(num);
    printf("[ ");
    for(int i= 0; i<_msize(arr2)/sizeof(int); ++i)
    {
        printf("%d, ", arr2[i]);
    }
    printf("]\n");
    free(arr2);

    return 1;
}
