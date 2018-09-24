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