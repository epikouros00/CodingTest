/****************************************
 * countSaure.c
 * consider counting the number of squares 
 * in the input cartesian coordiate space.
 * **************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int x, int y)
{
    int answer = 0;
    uint32_t numPoints = x * y;
    bool *status = (bool*)calloc(numPoints, sizeof(bool));
    
    for(int a = 0; a < numPoints; ++a)
    {
       status[a] = true; 
       int xa = a%x;
       int ya = a/y;
       for(int b = (a+1); b < numPoints; ++b)
       {
           status[b] = true; 
           // mark points to be excepted by a,b
           {
               int xb = b%x;
               int yb = b/y
                for(int point = b+1; point < numPoints; ++point)
                {
                    
           }
           for(int c = (b+1); c < numPoints; ++c)
           {
               if(status[c] == false) 
               {
                   status[c] = true;
                   //mark points to be excepted by (a,c) (b,c)
                   for(int d = (c + 1); d < numPoints; ++d)
                   {
                       if(status[d] == false) 
                       {
                           // (a,b,c,d) squre is made up
                           answer++;
                       }
                   }
                   // unmark points excepted by (a,c) (b,c)
               }
           }
           // unmark points excepted by (a,b) 
        }
    }

    free(status);
    return answer;
}

int main()
{
    printf("Input the size of the space(x,y): ");
    int x, y;
    scanf("%d %d",&x, &y);
    printf("Size: %d, %d\n", x, y);

    return 0;
}
