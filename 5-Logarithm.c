#include <math.h>
#include <stdio.h>

int main() {
  double x, result;
  printf("Enter a number : ");
  scanf("%lf", &x);

  result = log(x);
  
  printf("Log base e of %.2lf = %.2lf", x, result);
  return 0;
}