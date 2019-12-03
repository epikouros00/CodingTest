#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    long long longNum = num;
    while(true)
    {
        if(longNum == 1) { return answer; }
        else if((longNum & 0x1) == 0) {
            longNum /= 2;
        }
        else {
            longNum = (longNum * 3 + 1);
        }
        answer++;
        if(answer > 500) { return -1; }
    }    
}

int main()
{
    printf("Input number(1~8000000): ");
    int num;
    scanf("%d", &num);

    printf("result: %d \n", solution(num));

    return 1;
}

