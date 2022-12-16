#include <stdio.h>
#include <math.h>

#define f(x, y) ((x*x)+(y*y))

int main()
{
    float x0, y0;
    printf("Enter the initial values : ");
    scanf("%f%f", &x0, &y0);
    float h;
    printf("Enter the step size : ");
    scanf("%f", &h);
    float x;
    printf("Enter x : ");
    scanf("%f", &x);


    float k1, k2, k3, k4;
    for(float i = x0; i < x; i += h)
    {
        k1 = h*f(i,y0);
        k2 = h*f((i+(h/2.0f)),(y0+(k1/2.0f)));
        k3 = h*f((i+(h/2.0f)),(y0+(k2/2.0f)));
        k4 = h*f((i+h), (y0+k3));

        float y = (y0+((1.0f/6.0f)*(k1+2.0f*(k2+k3)+k4)));
        y0=y;
        printf("iter : %f\n", y0);
    }

    return 0;
}