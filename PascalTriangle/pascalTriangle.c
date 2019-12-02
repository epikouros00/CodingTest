#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _pascalTriangle
{
    unsigned long long* value;
}TypedefPascalTriangle;

TypedefPascalTriangle* makePascalTriangle(int num)
{
   TypedefPascalTriangle* pTri;
   pTri = (TypedefPascalTriangle*)malloc(sizeof(unsigned long long)*num);

   for(int i=0; i<=(num - 1); ++i)
   {
       pTri[i].value = (unsigned long long*)malloc(sizeof(unsigned long long)*(i+1));
       for(int j= 0; j <= i; ++j)
       {
            if(j == 0 || j == i) {
                pTri[i].value[j] = 1;
            }
            else {
                pTri[i].value[j] = pTri[i-1].value[j-1] + pTri[i-1].value[j];
                if(pTri[i].value[j] < pTri[i-1].value[j-1] || pTri[i].value[j] < pTri[i-1].value[j]){
                    printf("Error(%d step) - ULLONG_MAX value occured \n", i+1);
                }
            }
       }
   }
   return pTri;
}

int main()
{
    printf("Input number of brackets: ");
    
    int num;
    scanf("%d", &num);

    printf("number: %d\n", num);
    TypedefPascalTriangle *pPascalTriangle = makePascalTriangle(num);

    for (int i=0; i<num; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            printf("%llu ", pPascalTriangle[i].value[j]);
        }
        printf("\n");
    }
    
    /* free pPascalTriangle */
    for(int i=0; i<num; ++i)
    {
        free(pPascalTriangle[i].value);
    }
    free(pPascalTriangle);

    printf("%lld \n", LLONG_MAX);
    printf("%llu \n", ULLONG_MAX);
    return 1;
}

