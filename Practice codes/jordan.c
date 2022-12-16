#include <stdio.h>
#include <math.h>

#define M 5
#define N 6

int main()
{
    float a[M][N];

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(i != j)
            {
                float t = a[j][i]/a[i][i];

                for(int k = 0; k < N; k++)
                {
                    a[j][k] = a[j][k]-(a[i][k]*t);
                }
            }
        }
    }


    for(int i = 0; i < M; i++)
    {
        a[i][M] /= a[i][i];
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%.1f, ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// 2 3 16 31 103
// 235
// 3 16 31 103 235 
// 674
// 16 31 103 235 674
// 1669
// 31 103 235 674 1669
// 4526
// 103 235 674 1669 4526
// 11595