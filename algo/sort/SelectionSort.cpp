#include <vector>

void selectionSort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
  if(first == last) {
    return;
  }
  int min = *first;
  auto minIt = first;
  for(auto it = first; it != last; ++it) {
    if(*it <= min) {
      min = *it;
      minIt = it;
    }
  }
  *minIt = *first;
  *first = min;
  selectionSort(++first, last);
}

