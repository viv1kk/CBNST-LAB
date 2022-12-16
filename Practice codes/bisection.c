#include <stdio.h>
#include <math.h>
#define f(x) x-cos(x)

int main()
{
    float x0, x1;
    printf("Enter the interval (x0, y0) :");
    scanf("%f%f", &x0, &x1);
    printf("Enter the number of iteration : ");
    int iter;
    scanf("%d", &iter);
    float x3;
    while(iter--)
    {
        x3 = (x0+x1)/2.0f;
        if((f(x3)) > 0.0f)
            printf("Iteration : %f\n",x1 = x3);
        else
            printf("Iteration : %f\n",x0 = x3);
    }
    printf("\nRoot = %f", x3);
    return 0;
}