#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main()
{
    int n;
    printf("Enter the number of terms : ");
    scanf("%d", &n);

    float x[MAX], y[MAX];

    for(int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }

    float r;
    printf("Enter the value of x : ");
    scanf("%f", &r);

    int ind = 0;
    
    float ans = 0.0f;
    for(int i = 0; i < n; i++)
    {
        float num = 1.0f, den = 1.0f;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            num *= (r-x[j]);
            den *= (x[i]-x[j]);
        }
        ans += (num/den)*y[i];
    }
    printf("ans : %f", ans);
    return 0;
}