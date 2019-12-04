#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int answer = 0;
int sizeN = 0;

bool isPromising(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == arr[n]) return false;
        if((arr[i] - arr[n]) ==  (i - n)) return false;
        if((arr[i] - arr[n]) ==  (n - i)) return false;
    }
    return true;
}

void enumerate(int* arr, int n)
{
    
    if(n == sizeN)
    {
        answer++;
    }
    else
    {
        for(int i = 0; i < sizeN; ++i)
        {
            arr[n] = i;
            if(isPromising(arr, n))
            {
                enumerate(arr, n+1);
            }
        }
    }
}

int solution(int n) {
    answer = 0;
    sizeN = n;
    int* arr = (int*)malloc(sizeof(int)*n);

    enumerate(arr, 0);

    return answer;
}

int main()
{
    printf("Input size of chess table (n x n): ");
    int num;
    scanf("%d", &num);

    printf("Number of truce cases: %d \n", solution(num));

    return 1;
}

