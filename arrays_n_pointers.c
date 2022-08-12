#include <stdio.h>

// by jacob sorber
//    arrays are actually pointers.
//    this matters in understanding strings.
//    https://www.youtube.com/watch?v=uT-YLEHwVS4


int main() {
   int v[5] = {1,2,3,4,5};
  
   printf("v[0] = %i\n", v[0]);
   printf("v[1] = %i\n", v[1]);
   printf("v[2] = %i\n", v[2]);
   printf("v[3] = %i\n", v[3]);
   printf("v[4] = %i\n", v[4]);
  
  
    int *p = v;
    printf("p = %p\n", p);
    printf("val p as i = %i\n", *p);
  
  
  return 0;
}
