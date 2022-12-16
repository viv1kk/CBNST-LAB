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
    float u = (x-dt[0][0])/h;

    for(int i = 2; i < n+1; i++)
    {
        for(int j = 0; j < n-i+1; j++)
        {
            dt[j][i] = dt[j+1][i-1]-dt[j][i-1];
        }
    }

    float ans = 0.0f;
    float fact = 1.0f;
    float ch = u;
    ans = dt[0][1];

    for(int i = 2; i <= n; i++)
    {
        ans += (ch*dt[0][i])/fact;
        fact *= i;
        ch *= (u-(float)i+1.0f);
    }

    printf("ans : %f", ans);
    return 0;
}