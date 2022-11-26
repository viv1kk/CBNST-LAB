#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main()
{
    int n;
    float dt[MAX][MAX];

    printf("Enter the Number of data points : ");
    scanf("%d", &n);

    printf("Enter %d data points : \n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%f%f", &dt[i][0], &dt[i][1]);
    }

    float x;
    printf("Enter the value of x : ");
    scanf("%f", &x);

    float h = (dt[1][0]-dt[0][0]);
    float u = (x-dt[n-1][0])/h;

    for(int i = 2; i <= n; i++)
    {
        for(int j = n-1; j > i-2 ; j--)
        {
            dt[j][i] = dt[j][i-1]-dt[j-1][i-1];
        }
    }

    // printf("\n");
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < i+2; j++)
    //     {
    //         printf("%.2f ", dt[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    
    float ans = dt[n-1][1];
    float fact = 1.0f;
    float ch = u;
    for(int i = 2; i <= n; i++)
    {
        ans += (ch/fact)*dt[n-1][i];
        ch *= (u+(float)(i-1));
        fact *= i;
    }
    printf("ans = %f", ans);
    return 0;
}