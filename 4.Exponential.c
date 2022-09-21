#include <math.h>
#include <stdio.h>

int main() {
  double b, x, result;
  printf("Enter base and number : ");
  scanf("%lf%lf",&b, &x);

  result = pow(b,x);
  
  printf("Exponential of %.2lf = %.2lf", x, result);
  return 0;
}