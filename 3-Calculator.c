#include <stdio.h>


float add(float a, float b){ return a+b; }
float sub(float a, float b){ return a-b; }
float mul(float a, float b){ return a*b; }
float div(float a, float b){ return a/b; }


int main()
{
    printf("List of Operations : \n");
    printf("1. Input + for Additon.\n");
    printf("2. Input - for Subtraction.\n");
    printf("3. Input * for Multiplication.\n");
    printf("4. Input / for Division.\n");
    printf("Input e or E to EXIT\n\n");

    while(1)
    {
        fflush(stdin);
        char o;
        printf("\nChoose Operation : ");
        scanf("%c", &o);

        float a, b;
        switch(o)
        {
            case '+':{
                printf("Input Operands : ");
                scanf("%f%f", &a, &b);
                printf("%f\n", add(a,b));
            }
            break;
            case '-':
            {
                printf("Input Operands : ");
                scanf("%f%f", &a, &b);
                printf("%f\n",sub(a, b));
            }
            break;
            case '*':
            {
                printf("Input Operands : ");
                scanf("%f%f", &a, &b);
                printf("%f\n",mul(a, b));
            }
            break;
            case '/':
            {
                printf("Input Operands : ");
                scanf("%f%f", &a, &b);
                printf("%f\n", div(a, b));
            }
            break;
            case 'e':
            case 'E':
                {
                    printf("Exiting...\n");
                    return 0;
                }
                break;
            default:
                printf("\nUnsupported Operator!!\n");
        }

    }
    return 0;
}