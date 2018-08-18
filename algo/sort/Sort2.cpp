#include <vector>
#include <iostream>
#include <functional>

class SortableData {
  private:
    std::vector<int> &Data;
  public:
    SortableData(std::vector<int> &PData):Data{PData} {}
    void with(std::function<void(std::vector<int> &)> sortingAlgo) {
      sortingAlgo(this->Data); 
    }
};

auto sort = [](std::vector<int> &Data)->SortableData{
  return SortableData(Data); 
};


auto selectionSort = [](std::vector<int> &vector){
};

void printVector(const std::vector<int> &); 

int main() {
  std::vector<int> Data = {1,4,5,6,2,3};
  sort(Data).with(selectionSort); 
  printVector(Data);
  return 0;
}

void printVector(const std::vector<int> &vector) {
  for(const auto i : vector) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
