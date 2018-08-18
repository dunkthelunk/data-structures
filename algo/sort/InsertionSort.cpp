#include <vector>

typedef std::vector<int>::iterator VectIt;

void insertionSort(VectIt Begin, VectIt UnsortedBegin, VectIt End) {
  if(UnsortedBegin == End) {
    return;
  }
  auto It = UnsortedBegin;
  while(It != Begin && *(It - 1) > *It) {
    auto I = *It;
    *It = *(It - 1);
    *(It - 1) = I;
    --It;
  }
  insertionSort(Begin, UnsortedBegin+1, End);
}
