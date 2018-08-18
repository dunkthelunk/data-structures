#include <vector>
#include <iostream>

typedef std::vector<int>::iterator VectIt;

VectIt partition(VectIt Begin, VectIt End) {
 auto PivotVal = *(End-1); 
 auto Pivot = Begin;
 for(auto It = Begin; It < End-1; It++) {
   if(*It <= PivotVal) {
     auto Val = *It;
     *It = *Pivot;
     *Pivot = Val;
     ++Pivot;  
   }
 }
 auto CurPivVal = *Pivot;
 *Pivot = PivotVal;
 *(End-1) = CurPivVal;
 return Pivot;
}


void quickSort(VectIt Begin, VectIt End) {
  if (Begin==End || Begin+1 == End) {
    return;
  }
  for(auto It = Begin; It < End; It++) {
   std::cout << *It << ' ';
 }
 std::cout << '\n';
  auto Pivot = partition(Begin, End);
  quickSort(Begin, Pivot);
  quickSort(Pivot+1, End);
}

