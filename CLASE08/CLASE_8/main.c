#include <stdio.h>
#include <stdlib.h>
void imprimirArray (int *array, int n) { int i; for(i=0; i<n;i++) printf("\n%d",array[i]); printf("\n\n");}

void swap(int* array, int i, int j){
    int t;
    t = array[i];
    array[i] = array[j];
    array[j] = t;
}

void gnomeSort(int *array, int n){
  int i=1, j=2;
  while(i < n) {
    if (array[i - 1] < array[i]) {
      swap(array, i - 1, i);
      if (--i) continue;
    }
    i = j++;
  }
}

int main(){
    int a[] = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
    gnomeSort(a,10);
    imprimirArray(a,10);
    return 0;
}
