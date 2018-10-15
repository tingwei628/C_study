//quick sort with <stdlib.h>

#include<stdlib>
int cmpfunc_from_small_to_large (const void * a, const void * b) {
	   return ( *(int*)a - *(int*)b );
}

int cmpfunc_from_large_to_small (const void * a, const void * b) {
	   return ( *(int*)b - *(int*)a );
}

qsort(src, src_size, sizeof(int), cmpfunc_from_large_to_small);


// bubble_sort
void bubble_sort() {
  int _a = [4,5,6,1]; // sort from min to max
  int temp = 0;
  for (int i = 0; i < n; i++) {
    // n-1-j, each round, j compare items -1
    for (int j = 0; j < n - 1 - i; j ++) {
      if (a[j] > a[j+1]) {
        
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;

      }
    }
  }
}

