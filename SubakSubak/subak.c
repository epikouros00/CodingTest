#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) 
{
    char su[] = "��";
    char bak[] = "��";
    char* answer = (char*)malloc(sizeof(su) * n +1);
    memset(answer, 0, (sizeof(su)*n +1));
    for(int i=0; i<n; ++i)
    {
        if(i & 0x01)
        {
            strcat(answer, bak);
        }
        else
        {
            strcat(answer, su);
        }
    }
    return answer;
}

int main(void)
{
    printf("Intut a number(1~10000 intiger): ");
    int num;
    scanf("%d", &num);

//    char * result = malloc(sizeof("�ѱ�"));
//    result[0]= '��';
//    result[1] = '��';
//    printf("sizeof(\"�ѱ�\") = %d \n", sizeof("�ѱ�"));

    char * result = solution(num);
    printf("%s",result); 
    free(result);

    return 0;
}
