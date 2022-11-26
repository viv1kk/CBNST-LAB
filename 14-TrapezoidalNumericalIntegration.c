#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) x*x*x
#define MAX 100
int main()
{
    int n;
    float x[MAX], y[MAX];
    printf("Enter the number of subintervals : ");
    scanf("%d", &n);

    printf("Enter the interval (x0, x1) : ");
    scanf("%f%f", &x[0], &x[n]);

    float h = ((x[n]-x[0])/(float)n);

    printf("Common difference : %f\n", h);
    // values of x
    for(int i = 1; i < n; i++)
    {
        x[i] = x[i-1]+h;
    }

    for(int i = 0; i <= n; i++)
    {
        y[i] = f(x[i]);
    }

    float a = 0.0f;
    for(int i = 1; i < n; i++)
    {
        a += y[i];
    }
    a*=2;
    a += (y[0]+y[n]);
    a *= (h/2.0f);
    printf("ans : %f ", a);
    return 0;
}