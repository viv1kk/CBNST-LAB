#include <stdio.h>

#define f(x) (1.0f/(1.0f+x))

int main()
{
    float x1, xn;
    printf("Enter the interval : ");
    scanf("%f%f", &x1, &xn);
    float n;
    printf("Enter the no of subintervals : ");
    scanf("%f", &n);

    float h = (xn-x1)/n;
    float ans = (f(x1)+f(xn));
    int i = 1;

    float x = x1+h;
    while(i < n)
    {
        if(i%3 != 0)
            ans += (3*f(x));
        else
            ans += (2*f(x));
        x+=h;
        i++;
    }
    ans *= (3.0f*h/8.0f);
    printf("ans : %f", ans);
    return 0;
}