#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

bool decreasing(int a, int b) {
  return b < a;
}

bool increasing(int a, int b) {
  return a < b;
}

void swap(int *seq, int index1, int index2) {
  int temp = seq[index1];
  seq[index1] = seq[index2];
  seq[index2] = temp;
}

// equivalent to partition method of QuickSort
int reassemblePivotSides(int *seq, bool (* const ordering)(int, int), int seqbegin, int seqend) {
  int pivotIndex = seqbegin;
  int pivotVal = seq[seqend - 1];
  int currentVal;
  for(int i = seqbegin; i < seqend - 1; i++) {
    currentVal = seq[i];
    if(ordering(currentVal, pivotVal)) {
      swap(seq, i, pivotIndex);
      pivotIndex++;
    }
  }
  swap(seq, pivotIndex, seqend - 1);
  return pivotIndex;
}

void putKthAtK(int k, int *seq, int seqbegin, int seqend, bool (* const ordering)(int, int)) {
  int pivot = reassemblePivotSides(seq, ordering, seqbegin, seqend);
  if(pivot == k - 1) {
    return;
  }
  else if (pivot  > k - 1) {
    putKthAtK(k, seq, seqbegin, pivot, ordering); 
  } 
  else {
    putKthAtK(k - pivot - 1, seq, pivot + 1, seqend, ordering); 
  }
} 

int main() {
  int k;
  printf("k: ");
  scanf("%d", &k);
  int smallest = 1;
  printf("smallest?: ");
  scanf("%d", &smallest);
  int seqlen;
  printf("length of sequence: ");
  scanf("%d", &seqlen);
  int *seq = malloc(seqlen * sizeof *seq);
  printf("Enter %d elements\n", seqlen);
  for(int i = 0; i < seqlen; i++) {
    scanf("%d", &seq[i]);
  }
  bool (* const ordering)(int, int) = smallest ? increasing : decreasing;
  putKthAtK(k, seq, 0, seqlen, ordering); 
  printf("Kth %s element is: %i\n", smallest ? "smallest":"largest", seq[k-1]);
  free(seq);
  return 0;
}
