#include <vector>
#include <iostream>

extern void selectionSort(std::vector<int>::iterator first, std::vector<int>::iterator last); 
typedef std::vector<int>::iterator VectIt;
extern void insertionSort(VectIt Begin, VectIt UnsortedBegin, VectIt End); 
extern void mergeSort(VectIt, VectIt, int); 
extern void quickSort(VectIt, VectIt); 
void printVector(const std::vector<int> &); 

int main() {
  std::vector<int> Data = {23,100,56,56,1,4,5,6,2,2,3, 1};
//  selectionSort(Data.begin(), Data.end()); 
  // insertionSort(Data.begin(), Data.begin(), Data.end());
  // mergeSort(Data.begin(), Data.end(), Data.size());
 quickSort(Data.begin(), Data.end());
  printVector(Data);
  return 0;
}

void printVector(const std::vector<int> &vector) {
  for(const auto i : vector) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

