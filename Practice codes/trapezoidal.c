#include <stdio.h>
#include <math.h>

#define f(x) ((1.0f)/(1.0f+x))

int main()
{
    float x1, xn;
    printf("Enter the interval : ");
    scanf("%f%f", &x1, &xn);
    float n;
    printf("Enter the number of subintervals : ");
    scanf("%f", &n);

    float h = (xn-x1)/n;
    printf("h = %f",h);
    float ans = (f(x1)+f(xn));
    float x = x1+h;
    while(x <= xn-h)
    {
        printf("x = %f, y = %f\n",x, f(x));
        ans += (2.0f*f(x));
        x += h;

    }
    ans = ans*(h/2.0f);

    printf("ans : %f", ans);
    return 0;
}