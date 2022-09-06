//  Name: Jacob Bahn
//  Assignment number: 2
//  Assignment: Sort Comparison
//  File name: sortcomparison.cpp
//  Date last modified: September 5, 2022
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <iostream>
#include <vector>
#include <chrono>


void insertion_sort(std::vector<int>& vec) {
  if (vec.size() < 1) {
    return;
  }
  for (int i = 0; i < vec.size() - 1; i++) {
    for (int j = 0; j < vec.size() - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        std::swap(vec[j], vec[j + 1]);
      }
    } 
  }
}


void merge_sort() {}

int main() {
  std::vector<int> vec{2, 1, 9, 1, 0, 8, 5, 7, 30, 12};
  
  auto isort_start = std::chrono::high_resolution_clock::now();
  insertion_sort(vec);
  auto isort_end = std::chrono::high_resolution_clock::now();

  for (auto i : vec) {
    std::cout << i << " ";
  }

  auto isort_duration = std::chrono::duration_cast<std::chrono::microseconds>(isort_end - isort_start);

  std::cout << "\nIt took insertion_sort " << isort_duration.count() << " microseconds to execute.";
}
