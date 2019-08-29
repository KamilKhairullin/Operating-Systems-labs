#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  int int_maximum;
  float float_maximum;
  double double_maximum;

  int_maximum = INT_MAX;
  float_maximum = FLT_MAX;
  double_maximum = DBL_MAX;

  printf("MAX_integer is : %d\n", int_maximum);
  printf("MAX_float is : %f\n", float_maximum);
  printf("MAX_double is : %.10e\n", double_maximum);

  return 0;
}
