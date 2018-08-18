#include <vector>

typedef std::vector<int>::iterator VectIt;

void merge(VectIt Begin, VectIt Mid, VectIt End) {
  std::vector<int> FirstHalf(Begin, Mid+1);
  std::vector<int> SecondHalf(Mid + 1, End);
  
  auto FirstIt = FirstHalf.begin();
  auto SecondIt = SecondHalf.begin();
  for(auto It = Begin; It < End; It++) {
    if(FirstIt == FirstHalf.end()) {
      *It = *SecondIt;
      SecondIt++;
      continue;
    }

    if(SecondIt == SecondHalf.end()) {
      *It = *FirstIt;
      FirstIt++;
      continue;
    }
    if(*FirstIt < *SecondIt) {
      *It = *FirstIt;
      FirstIt++;
    }
    else {
      *It = *SecondIt;
      SecondIt++;
    }
  }
}

void mergeSort(VectIt Begin, VectIt End, int Size) {
  if (Size == 1) {
    return;
  }
  auto Mid = Begin + Size/2 - 1; 
  mergeSort(Begin, Mid+1, Size/2);
  mergeSort(Mid+1, End, Size -  Size/2);
  merge(Begin, Mid, End);
}

