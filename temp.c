#include<stdio.h>
#include <stdlib.h>


void printMatrix(float* mat, int x, int y)
{
    printf("\n Matrix :\n");
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            printf("\t%f,\t", mat[(x*i)+j]);
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    int n = 3;
    float* mat = (float*) calloc((n*n), sizeof(float));

    for(int i = 0; i < n; i++)
    {
        printf("Input the coefficients of #%d : ",i+1);
        for(int j = 0; j < n; j++)
        {
            scanf("%f", &mat[(n*i)+j]);
        }
    }

    printMatrix(mat, n, n);


    for(int j = 0 ; j < n; j++)
    {
        for(int i = j+1; i < n; ++i)
        {
            printf("%f , ", mat[((n*i)+(j))]);
        }
        printf("\n");
    }


    return 0;
}

// 1 2 3
// 4 5 6
// 7 8 9

