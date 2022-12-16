#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the no. of data points : \n");
    scanf("%d", &n);
    printf("Enter the data points : \n");
    float x[n], y[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }
    float xa;
    printf("Enter the value of x : ");
    scanf("%f", &xa);

    float ans = 0.0f;
    for(int i = 0; i < n; i++)
    {
        float num=1.0f, den = 1.0f;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                num *= (xa-x[j]);
                den *= (x[i]-x[j]);
            }
        }
        ans += (num/den)*y[i];
    }

    printf("ans : %f", ans);
    return 0;
}