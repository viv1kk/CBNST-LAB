#include <stdio.h>
#define f(x) x*x*x -x -4

typedef struct Interval
{
    double x1;
    double fx1;
    double x2;
    double fx2;
}Inv;

void findInterval(Inv* in)
{
    for(double x = -50; x < 50; ++x)
    {
        if(in->x1 == 0 || in->x2 == 0 )
        {
            double solve = f(x);

            if(solve < 0)
            {
                in->x1 = x;
                in->fx1 = solve;
            }
            else if(solve > 0)
            {
                in->x2 = x;
                in->fx2 = solve;
            }
            else
            {
                break;
            }
        }
    }
    printf("The interval is %lf, %lf --- %lf, %lf\n\n", in->x1, in->x2, in->fx1, in->fx2);
}

double evalFunc(Inv *in)
{
    double c = (((in->x1)*(in->fx2))-((in->x2)*(in->fx1)))/((in->fx2)-(in->fx1));
    double x = c;
    double solve = f(x);
    if((in->fx1)*c < 0)
    {
        in->x1 = c;
        in->fx1 = solve;
    }
    else
    {
        in->x2 = c;
        in->fx2 = solve;
    }
    return c;
}


int main()
{
    int iter = 10;
    Inv e;
    e.x1 = 0;
    e.x2 = 0;
    // e.fx1 = -1;
    // e.fx2 = 16;
    findInterval(&e);
    double root;

    for(int i = 1 ; i <= iter; i++)
    {
        root = evalFunc(&e);   
        printf("@ iteration %d: %lf, %lf, root %lf\n", i, e.x1, e.x2, root);
    }
    printf("The root is %lf", root);
    return 0;
}