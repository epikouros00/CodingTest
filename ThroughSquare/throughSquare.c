#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long getGCD(int a, int b)
{
    while(a != b) {
        if(a > b) { a -= b; }
        else { b -= a; }
    }    
    return a;
}
    
long long solution(int w, int h) {
    long long answer = w * h;
    return (answer - (w + h - getGCD(w, h)));
}

int main()
{
    printf("Input w, h: ");
    int w, h;
    scanf ("%d", &w);
    scanf ("%d", &h);

    printf("remain square: %lld", solution(w, h));
    
    return 1;
}

