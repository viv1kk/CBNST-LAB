#include <stdio.h>
// #define f(x) 2*x*x +5*x-1
#define f(x) x*x-30
// #define f(x) (x*x*x)-(5*x)+3
#define ITER 18

typedef struct interval
{
    double x1;
    double x2;
}Iv;


void findInterval(Iv* val)
{
    val->x1 = -60, val->x2 =-60;

    for(int x = -10; x < 50; x++)
    {
        if(val->x1 == -60 || val->x2 == -60 )
        {
            double solve = f(x);
            if(solve < 0)
                val->x1 = x;
            else if(solve > 0)
                val->x2 = x;
        }
    }
    printf("Range : (%f, %f)\n", val->x1, val->x2);
}

double evalfunc(Iv* val)
{
    double x3 = (val->x1+val->x2)/2;
    double solve = f(x3);

    if(solve < 0)
    {
        val->x1 = x3;
    }
    else if(solve > 0)
    {
        val->x2 = x3;
    }

    printf("%lf, %lf\n", val->x1, val->x2);
//     val->x1 = 10.0;
//     val->x2 = 20.0;
    return x3;
}


int main()
{
    // 2x^2 + 5x - 1 = 0
    int iteration = ITER;
    double root;

    Iv val;

    findInterval(&val);

    for(int i = 0; i < iteration; i++)
    {
        printf("Iter #%d ",i);
        root = evalfunc(&val);
    }

    printf("%lf, %lf\n", val.x1, val.x2);
    printf("Root : %lf\n", root);

    return 0;
}