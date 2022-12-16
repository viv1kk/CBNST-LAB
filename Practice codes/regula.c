#include <stdio.h>
#include <math.h>
#define f(x) ((x*x*x)-(2*x)-5)

int main()
{
    float x0, x1;
    // printf("Input the interval : ");
    // scanf("%f%f", &x0, &x1);
 
    for(float i = -50.0 ; i < 50.0; i++)
    {
        if(f(i) > 0.0f) 
        {
            x1 = i;
            break;
        }
    }

    for(float  i = x1; i >-50; i--)
    {
        if(f(i) < 0.0f)
        {
            x0 = i;
            break;
        }
    }

    printf("Intervals (%f, %f)", x0, x1);


    // int iter;
    // printf("Enter the no of iteration : ");
    // scanf("%d", &iter);

    // float x2;
    // while(iter--)
    // {
    //     x2 = (x0-(((x1-x0)/(f(x1)-f(x0)))*f(x0)));
    //     if(f(x2)*f(x0) < 0.0f)
    //         x1 = x2;
    //     else if(f(x2)*f(x0) > 0.0f)
    //         x0 = x2;
    //     else
    //         break;
    //     printf("Root : %f\n", x2);
    // }
    // printf("\nRoot : %f\n", x2);


    float EPS;
    printf("Enter the no of iteration : ");
    scanf("%f", &EPS);

    float x2;
    do
    {
        x2 = (x0-(((x1-x0)/(f(x1)-f(x0)))*f(x0)));
        if(f(x2)*f(x0) < 0.0f)
            x1 = x2;
        else if(f(x2)*f(x0) > 0.0f)
            x0 = x2;
        else
            break;
        printf("Root : %f    %f    %f\n",x0, x1,x2);
    }while(fabs(x0-x1) > EPS);
    printf("\nRoot : %f\n", x2);

    return 0;
}