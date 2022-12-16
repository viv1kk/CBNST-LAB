#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of data points : ");
    scanf("%d", &n);

    float dt[n][n+1];
    printf("Enter the data points : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f%f",&dt[i][0],&dt[i][1]);
    }
    printf("Find value for y @ x = ");
    float x;
    scanf("%f", &x);

    float h = dt[1][0]-dt[0][0];
    float u = (x-dt[n-1][0])/h;

    for(int i = 2; i <= n; i++)
    {
        for(int j = n-1; j >= i-1; j--)
        {
            dt[j][i] = dt[j][i-1]-dt[j-1][i-1];
        }
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = i-1; j < n; j++)
        {
            printf(" %f , ", dt[i][j]);
        }
        printf("\n");
    }

    float ans = 0.0f;
    float fact = 1.0f;
    float ch = u;
    ans = dt[n-1][1];

    for(int i = 2; i <= n; i++)
    {
        ans += (ch*dt[n-1][i])/fact;
        fact *= i;
        ch *= (u+(float)i-1.0f);
    }

    printf("ans : %f", ans);
    return 0;
}