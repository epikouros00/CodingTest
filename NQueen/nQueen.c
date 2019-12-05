#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int answer = 0;
int sizeN = 0;

bool isPromising(int* arr, int pos)
{
    for(int i = 0; i < pos; ++i)
    {
        if(arr[i] == arr[pos]) return false;
        if((arr[i] - arr[pos]) ==  (i - pos)) return false;
        if((arr[i] - arr[pos]) ==  (pos - i)) return false;
    }
    return true;
}

void enumerate(int* arr, int pos)
{
    if(pos == sizeN)
    {
        answer++;
    }
    else
    {
        for(int i = 0; i < sizeN; ++i)
        {
            arr[pos] = i;
            if(isPromising(arr, pos))
            {
                enumerate(arr, pos+1);
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


/////////////////////////////////////////////////////////////
int size, ans, col[15], inc[30], dec[30];
void sol(int r)
{
    if(r == size)
    {
        ans++;
    }
    else
    {
        for(int i=0; i<size; ++i)
        {
            if(!col[i] && !inc[r+i] && !dec[size+(r-i)])
            {
                col[i] = inc[r+i] = dec[size+(r-i)] = 1;    // inc[r+i]->'/'direction, dec[size+r-i]->'\'direction
                sol(r+1);
                col[i] = inc[r+i] = dec[size+(r-i)] = 0;
            }
        }
    }
}

int solution2(int n)
{
    size = n;
    ans = 0;
    memset(col, 0, sizeof(int)*15);
    memset(inc, 0, sizeof(int)*30);
    memset(dec, 0, sizeof(int)*30);
    sol(0);
    return ans;
}
    
////////////////////////////////////////////////////////////
int main()
{
    printf("Input size of chess table (n x n): ");
    int num;
    scanf("%d", &num);

    time_t start_, end_;
    int result = 0;
//    start_ = clock();
//    result = solution(num);
//    end_ = clock();
//    printf("%lld %lld \n",start_, end_);
//    printf("Table size: %2d -> Number of truce cases: %7d // Time complexity: %lld(msec)\n", num, result, (clock()-start_));

    start_ = clock();
    result = solution2(num);
    end_ = clock();
    printf("%lld %lld \n",start_, end_);
    printf("Table size: %2d -> Number of truce cases: %7d // Time complexity: %lld(msec)\n", num, result, (clock()-start_));

    return 1;
}

