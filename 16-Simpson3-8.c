#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MAX 100
#define f(x) (1/(1+x))

int main()
{
    int n;
    float x[MAX], y[MAX];
    printf("Enter the number of subintervals : ");
    scanf("%d", &n);
    assert(n%3 == 0);
    printf("Enter the interval (x0, x1) : ");
    scanf("%f%f", &x[0], &x[n]);

    float h = ((x[n]-x[0])/(float)n);

    printf("Common difference : %f\n", h);
    // values of x
    for(int i = 1; i < n; i++)
        x[i] = x[i-1]+h;

    for(int i = 0; i <= n; i++)
        y[i] = f(x[i]);

    float a = 0.0f;
    for(int i  = 1; i < n; i++)
    {
        if((i%3) == 0) a += 2*y[i];
        else a+=3*y[i];
    }
    a += y[0]+y[n];
    a *= (h*3.0f/8.0f);

    for(int i = 0; i <= n; i++)
        printf("y[%d] = %f\n", i, y[i]);

    printf("\nNumerical Integration is %f", a);
    return 0;
}