#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive Integer : ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Please Retry with a Positive Integer!\n");
        return 0;
    }
    
    int s = 0, e = n, ans = 0;
    while(s <= e)
    {
        int m = s+(e-s)/2;
        int sm = m*m*m;
        if(sm > n)
            e = m-1;
        else if(sm < n)
        {
            s = m+1;
            ans = m;
        }
        else
        {
            ans = m;
            break;
        }
    }    
    printf("%d", ans);
    return 0;
}