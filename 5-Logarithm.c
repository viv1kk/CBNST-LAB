#include <math.h>
#include <stdio.h>

int main() {
  double x, result;
  int n;
  printf("Enter Base and number : ");
  scanf("%d %lf",&n, &x);

  result = log(x)/log(n);
  
  printf("Log base e of %.2lf = %.2lf", x, result);
  return 0;
}