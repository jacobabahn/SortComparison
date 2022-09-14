//  Name: Jacob Bahn
//  Assignment number: 2
//  Assignment: Sort Comparison
//  File name: sortcomparison.cpp
//  Date last modified: September 5, 2022
//  Honor statement: I have neither given nor received any unauthorized help on
//  this assignment.

#include <chrono>
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &vec) {
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

void merge(std::vector<int> &a, int p, int q, int r) {
  int n1 = q - p + 1, n2 = r - q, i, j;         // |  c1
  std::vector<int> left(n1 + 1), right(n2 + 1); // |  c2
  for (i = 0; i < n1; i++) {                    // +
    left[i] = a[p + i];                         // |  n + 1
  }                                             // +
  for (j = 0; j < n2; j++) {                    // +
    right[j] = a[q + j + 1];                    // |  n + 1
  }                                             // +
  left[n1] = INT_MAX;            // Place sentinel            // |  c3
  right[n2] = INT_MAX;           // values                   // |  c4
  i = j = 0;                     // |  c5
  for (int k = p; k <= r; k++) { // +
    if (left[i] <= right[j]) {   // |
      a[k] = left[i];            // |
      i++;                       // |  n
    }                            // |
    else {                       // |
      a[k] = right[j];           // |
      j++;                       // |
    }                            // |
  }
}

void merge_rec(std::vector<int> &a, int p, int r) {
  if (p < r) {
    // int q = (p + r) / 2;
    int q = p + (r - p) / 2;
    merge_rec(a, p, q);
    merge_rec(a, q + 1, r);
    merge(a, p, q, r);
  }
}

void merge_sort(std::vector<int> &a) { // Call to recursive method
  merge_rec(a, 0, a.size() - 1);
}

int main() {
  std::vector<int> vec;
  std::vector<int> vecMerge;

  for (int i = 0; i < 10000; i++) {
    vec.push_back(rand() % 100);
  }

  for (int i = 0; i < 10000; i++) {
    vecMerge.push_back(rand() % 100);
  }

  auto isort_start = std::chrono::high_resolution_clock::now();
  insertion_sort(vec);
  auto isort_end = std::chrono::high_resolution_clock::now();

  auto msort_start = std::chrono::high_resolution_clock::now();
  merge_sort(vecMerge);
  auto msort_end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> isort_duration =
      isort_end - isort_start;
  std::chrono::duration<double, std::milli> msort_duration =
      msort_end - msort_start;

  std::cout << "\nIt took insertion_sort " << isort_duration.count()
            << " milliseconds to execute.";
  std::cout << "\nIt took merge_sort " << msort_duration.count()
            << " milliseconds to execute.";
}
