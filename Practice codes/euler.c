#include <stdio.h>
#include <math.h>

#define f(x, y) (x+y+(x*y))

int main()
{
    float x0, y0;
    printf("Enter (x0, y0) : ");
    scanf("%f%f", &x0, &y0);
    float h;
    printf("Enter the step size : ");
    scanf("%f", &h);
    float x;
    printf("Enter x : ");
    scanf("%f", &x);

    for(float i = x0; i < x; i+=h)
    {
        y0 = y0+(h*f(i, y0));
    }
    printf("ans : %f", y0);
    return 0;
}