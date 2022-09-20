#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define f(x) x*x*x-5
// #define d(x) 3*x*x
#define f(x) (x*x*x)-x-4
#define d(x) (3*x*x)-1

/*
double f(double x)
{
    return cos(x)-exp(x);
}
double d(double x)
{
    return -sin(x)-exp(x);
}*/

int getx0()
{
    int neg = -60, pos = -60;
    for(int i = -50; i < 50; ++i)
    {
        if(f(i) < 0)
            neg = i;
        else
            pos = i;
        if(neg != -60 && pos != -60 && f(neg)*f(pos)< 0)
            break;
    }
    printf("%d, %d\n", neg, pos);
    return (abs(f(neg)) < abs(f(pos)))?neg:pos;
}
/*
double newtonRaphson(double x0, int iter)
{
    double x1 = x0;
    double f1, d1;
    for(int i = 0; i < iter; i++)
    {
        f1 = f(x1);
        d1 = d(x1);

        double x2 = x1 - (f1/d1);
        x1 = x2;

        printf("Iter %d x %lf\n", i,x1);
    }
    return x1;
}*/


double newtonRaphson(double x0, int iter, int i)
{
    printf("Iteration : %d, x = %lf\n", i, x0);
    if(iter == 1)
        return x0;
    return newtonRaphson((x0-((f(x0))/(d(x0)))), iter-1, i+1);
}


int main()
{
    double x0 = (double)getx0();
    double root = newtonRaphson(x0, 8,1);
    printf("\nRoot is : %lf\n", root);
    return 0;
}