#include<stdio.h>
#include<math.h>
#define f(x, y) (1-y)
int main()
{
    float x0, y0, h, x;
    printf("Enter the x0 and y0 : ");
    scanf("%f%f", &x0, &y0);
    
    printf("Enter the value of h : ");
    scanf("%f", &h);

    printf("Calcualte y(x) where x = : ");
    scanf("%f", &x);

    float xi = x0;
    float y = y0;
    for(float i = xi; i < x; i+=h)
    {
        y = y +(h*f(i, y));
    }
    printf("The value of y = %f", y);
    return 0;
}