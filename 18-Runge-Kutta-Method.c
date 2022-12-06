#include <stdio.h>
#include <stdlib.h>

#define f(x, y) ((x*x)+(y*y) )

int main()
{
    float x0, y0, h, x;
    printf("Enter the x0 and y0 : ");
    scanf("%f%f", &x0, &y0);
    
    printf("Enter the value of h : ");
    scanf("%f", &h);

    printf("Calcualte y(x) where x = : ");
    scanf("%f", &x);

    float k1, k2, k3, k4, y;

    int n = (int)((x-x0)/h);

    printf("\t\tx\t\ty\n");
    for(int i = 0; i < n; i++)
    {
        k1 = h*f(x0, y0);
        k2 = h*f((x0+(h/2.0f)),(y0+(k1/2.0f)));
        k3 = h*f((x0+(h/2.0f)),(y0+(k2/2.0f)));
        k4 = h*f((x0+h),(y0+k3));
        y = (y0+((1.0f/6.0f)*(k1+(2.0f*k2)+(2.0f*k3)+k4)));
        x0 = x0+h;
        printf("Iteration %d :\t%f @ x = %.2f\n", i+1, y, x0);
        y0 = y;
    }
    return 0;
}