#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (-cos(x)-1+(3*x))
#define d(x) (sin(x)+3)
int main()
{
    float x0, x1;

    for(float i = -49.0f;; i++)
    {
        if(f(i) > 0.0f)
        {
            x1 = i;
            break;
        }
    }
    
    for(float i = x1; ; i--)
    {
        if(f(i) < 0.0f)
        {
            x0 = i;
            break;
        }
    }

    // printf("Intervals (%f, %f)", x0, x1);
    // x0 = (x1 < x0)?x1:x0;
    // int iter;
    // scanf("%d", &iter);
    
    // while(iter--)
    // {
    //     x1 = x0 - (f(x0)/d(x0));
    //     x0 = x1;
    //     printf("Root : %f\n", x0);
    // }


    float eps;
    printf("Enter epsilon : ");
    scanf("%f", &eps);


    x0 = (fabs(x0) < x1)?x0:x1;
    int f = 0;
    do
    {
        x1 = x0-(f(x0)/d(x0));
        if(fabs(x1-x0) < eps)
        {
            f = 1;
        }
        printf("Root : %f\n", x1);
        x0 = x1;
    }while(f == 0);
    return 0;
}