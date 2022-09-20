#include <math.h>
#include <stdio.h>

int main() {
  double x, result;
  printf("Enter a number : ");
  scanf("%lf", &x);

  result = exp(x);
  
  printf("Exponential of %.2lf = %.2lf", x, result);
  return 0;
}