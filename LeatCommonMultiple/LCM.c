#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isContain(int* arr, int num, int size)
{
    for(int i=0; i<size; ++i)
    {
        if(arr[i] == num) { return true; }
    }
    return false;
}

long long getGCD(long long a, long long b)
{
    long long gcd = 0;
    for(long long i=1; i<=a && i<=b; ++i)
    {
        if((a%i == 0) && (b%i == 0)) { gcd = i; }
    }
    return gcd;
}

long long getLCM(long long a, long long b)
{
    return (a/getGCD(a, b)*b);
}

long long solution(int arr[], size_t arr_len) {
    long long answer = 1;
    for(int i = 0; i < arr_len; ++i)
    {
        answer = getLCM(answer,arr[i]);
    }
    return answer;
}

int main()
{
    printf("input numbers for LCD (1~100):");
    int *arrNum = (int*)malloc(sizeof(int));
    int cnt = 0;
    char c = 0;
    while((c = getc(stdin)) != '\n')
    {
       ungetc(c, stdin);
       arrNum = (int*)realloc(arrNum, sizeof(int)*(++cnt));
       scanf("%d", &arrNum[cnt-1]);
    } 
    printf ("length=%d\n", cnt);
    printf("Leat Common Multiple number is %lld.\n",solution(arrNum, cnt));
    free(arrNum);
    return 1;
}

