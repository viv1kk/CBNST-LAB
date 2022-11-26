#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main()
{
    float dt[MAX][MAX];
    int n;

    printf("Enter the number of data points : ");
    scanf("%d", &n);
    printf("Enter data points : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f %f", &dt[i][0], &dt[i][1]);
    }

    float h = (dt[1][0]-dt[0][0]);
    float x;
    printf("Find the value of x ? : ");
    scanf("%f", &x);
    float u = (x-dt[0][0])/h;

    for(int j = 2; j <= n; j++)
    {
        for(int i = 0; i < n-j+1; i++)
        {
            dt[i][j] = dt[i+1][j-1]-dt[i][j-1];
        }
    }

    // for(int j = 0; j < n; j++)
    // {
    //     for(int i = 2; i <= n-j; i++)
    //     {
    //         printf("%.2f ", dt[j][i]);
    //     }
    //     printf("\n");
    // }
    

    float ans = 0.0f;

    ans += dt[0][1];
    float ch = u;
    // printf("ch = %.2f, h = %.2f\n", ch, h);
    float fact = 1.0;
    for(int i = 2; i <= n; i++)
    {
        ans += ((ch/fact)*dt[0][i]);
        // printf("%.2f dt = %.2f\n", ans, dt[0][i]);
        ch *= (u-(float)(i-1));
        fact *= i;
    }

    printf("ans = %.2f", ans);
    return 0;
}