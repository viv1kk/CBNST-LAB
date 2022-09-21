#include <stdio.h>
#include <stdlib.h>
#define FLT_MIN  -5000000000000000000.0f

void printMatrix(double*, int, int );
int checkUpperTriangle(double*, int);
double getValuesOfVariables(double*, double*, double*, int, int);
int checkIfMatrixIsValid(double*, int);
void performRowOperations(double*, double*, int);
void scaleFunction(double*, double*, double, int, int);
void subtractFunc(double*, double*, int, int, int);

int main()
{
    int n;
    printf("Input the Number of variables in the equation : ");
    scanf("%d", &n);

    if(n < 1) { printf("Need Atleast 1 variable in equation!!"); return 0;}

    double* mat = (double*) calloc((n*n), sizeof(double));
    double* rhs = (double*) calloc(n, sizeof(double));

    for(int i = 0; i < n; i++)
    {
        printf("Input the coefficients of #%d : ",i+1);
        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &mat[(n*i)+j]);
        }
        printf("Input the rhs value of eq #%d : ", i+1);
        scanf("%lf", &rhs[i]);
        printf("\n");
    }

    performRowOperations(mat, rhs, n);

    if(checkIfMatrixIsValid(mat, n))
    {
        printf("\nMatrix is Valid for extracting Values!\n");
        double* ans = (double*) calloc(n, sizeof(double));
        if(ans != NULL)
        {
            for(int i = 0; i < n; ++i)
            {
                ans[i] = FLT_MIN;
            }
            double x = getValuesOfVariables(mat, rhs, ans, n, 0);
            for(int i = 0; i < n; ++i)
            {
                printf("\nValue of x%d = %lf", i, ans[i]);
            }
            printf("\n\n");
        }
        else printf("\nMemory not Allocated !\n");
        free(ans);
    }
    else
    {
        printf("\nMatrix is not Valid for extracting Values!\n");
    }
    printMatrix(mat, n, n);
    printMatrix(rhs, 1, n);

    free(mat);
    free(rhs);
}

void performRowOperations(double* mat, double* rhs, int s)
{
    if(checkUpperTriangle(mat, s))
    {
        int index;
        double temp1, temp2;

        for(int i = 0; i < s; i++)
        {
            for(int j = 0 ; j < s; j++)
            {
                index = (s*j)+i;

                temp1 = mat[(s*i)+i];
                if(i < j)
                {
                    temp2 = mat[index];
                    printf("\ntemp1 = %lf, temp2 = %lf\n",temp1, temp2);
                    scaleFunction(mat, rhs, temp2, s, i);
                    scaleFunction(mat, rhs, temp1, s, j);
                    subtractFunc(mat, rhs, s, i, j);
                }
                
            }
            if(!checkUpperTriangle(mat, s)) return;
        }
    }
}

void scaleFunction(double* mat, double* rhs, double factor, int s, int ind)
{
    int offset = (ind*s);
    for(int i = 0; i < s; ++i)
    {
        mat[offset+i] = mat[offset+i]*factor;
    }
    rhs[ind] = rhs[ind]*factor;
    printf("\nAfter Scaling Function:\n");
    printMatrix(rhs, 1, s);
    printMatrix(mat, s, s);
}

void subtractFunc(double* mat, double* rhs, int s, int i1, int i2)
{
    // eq2 = eq1 - eq2
    int off1 = (s*i1);
    int off2 = (s*i2);

    for(int i = 0; i < s; ++i)
    {
        mat[off2+i] = mat[off1+i]-mat[off2+i];
    }
    rhs[i2] = rhs[i1]-rhs[i2];

    printf("\nAfter Subtraction Function:\n");
    printMatrix(rhs, 1, s);
    printMatrix(mat, s, s);
}



int checkUpperTriangle(double* mat, int s)
{
    int flag = 0;

    int ind = 0;
    // BRUTEFORCE WAY

    // for(int i = 0;  i < s; i++)
    // {
    //     for(int j = 0; j < s; j++)
    //     {
    //         ind = (i*s)+j;
    //         if(j > i && mat[ind] != 0.0)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag) break;
    // }

    // OPTIMISED WAY

    for(int i = 1; i < s; i++)
    {
        for(int j = 0; j < i; j++)
        {
            ind = (i*s)+j;
            if(mat[ind] != 0.0)
            {
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    return flag;
}

double getValuesOfVariables( double* mat, double* rhs, double* ans, int s, int n)
{
    // return 0.0;
    if(n == s)
        return 0.0;
    if(ans[n] != FLT_MIN)
        return ans[n];

    int index = (n*s)+n;
    float val = 0.0;

    for(int i = 1; i < s-n; i++)
    {
        val += mat[index+i]*getValuesOfVariables(mat, rhs, ans, s, n+i); 
    }
    val = (rhs[n]-val)/mat[index];
    ans[n] = val;
    // printf("n = %d, val = %f \n", n, val);
    return val;
}

int checkIfMatrixIsValid(double* mat, int s)
{
    if(mat[0] == 0.0 || mat[(s*s)-1] == 0.0) return 0;
    return (checkUpperTriangle(mat, s))?0:1;
}

void printMatrix(double* mat, int x, int y)
{
    printf("\n Matrix :\n");
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            printf("\t%lf,\t", mat[(x*i)+j]);
        printf("\n");
    }
    printf("\n\n");
}

// 6 24 54 
// 96
// 0 140 340
// 440
// 0 0 4
// 20

// 2 1 1
// 10
// 3 2 3
// 18
// 1 4 9
// 16

// 1 4 9
// 16
// 2 1 1
// 10
// 3 2 3
// 18

// 5
// 2 3 16 31 103
// 235
// 3 16 31 103 235 
// 674
// 16 31 103 235 674
// 1669
// 31 103 235 674 1669
// 4526
// 103 235 674 1669 4526
// 11595