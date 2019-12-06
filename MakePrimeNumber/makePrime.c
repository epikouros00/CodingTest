#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int n)
{
    for(int i=2; i<=(n/i); ++i)
    {
        if((n%i) == 0) { return false; }
    }
    return true;
}

int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for(int i = 0; i<(nums_len - 2); ++i)
    {
        for(int j = (i+1); j<(nums_len - 1); ++j)
        {
            for(int k = (j+1); k<(nums_len); ++k)
            {
                if(isPrime(nums[i]+nums[j]+nums[k])) { 
//                    printf("%d, ",(nums[i]+nums[j]+nums[k]));
                    answer++; 
                }
            }
        }
    }
    return answer;
}

int main()
{
    printf("Input at least 3 numbers to make prime(1~1000): ");
    int* arrNum = (int*)malloc(sizeof(int));
    int cnt = 0;
    char c = 0;
    while((c=getc(stdin))!='\n')
    {
        ungetc(c, stdin);
        arrNum = (int*)realloc(arrNum, sizeof(int)*++cnt);
        scanf("%d", &arrNum[cnt-1]);
    }

    for(int i=0; i<cnt; ++i)
    {
        printf("%d, ",arrNum[i]);
    }
    printf("\n");

    int result = solution(arrNum, cnt);

    printf("Number of cases: %d\n", result);

    return 1;
}

        
