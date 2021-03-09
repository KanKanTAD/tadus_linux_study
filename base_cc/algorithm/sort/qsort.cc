#include <algorithm>
#include <fmt/format.h>
#include <iostream>
#include <iterator>
#include <tadcc/string_alg.h>
#include <tadcc/tadcc.hpp>
#include <vector>
template <typename T>
void v_qsort(T *arr, const int beg_idx, const int end_idx,
             const size_t a_size) {
  if (!(beg_idx < end_idx)) {
    return;
  }
  for (auto i = 0; i < a_size; ++i) {
    std::cout << arr[i] << ",";
  }
  std::cout << std::endl;
  auto tag__ = beg_idx;
  auto left = beg_idx + 1;
  auto right = end_idx;
  while (beg_idx < left && left <= right && right <= end_idx) {
    while (left <= right && arr[tag__] <= arr[right]) {
      right--;
    }
    if (!(arr[tag__] <= arr[right])) {
      std::swap(arr[tag__], arr[right]);
      tag__ = right--;
    }
    while (left <= right && arr[tag__] > arr[left]) {
      left++;
    }
    if (!(arr[tag__] > arr[left])) {
      std::swap(arr[tag__], arr[left]);
      tag__ = left++;
    }
  }
  v_qsort(arr, beg_idx, tag__ - 1, a_size);
  v_qsort(arr, tag__ + 1, end_idx, a_size);
}
int main(int argc, char **argv) {
  std::string typename_ = argv[1];
  std::string str_ = argv[2];
  std::vector<std::string> result;
  tadcc::pattern_split(str_, ",", result);
  tadcc::str_lower(tadcc::trim(typename_));
  fmt::print("typename :{0}\n", typename_);
  if (typename_ == "int") {
    int vk[result.size()];
    std::transform(result.begin(), result.end(), vk,
                   [](const std::string &v) -> int { return std::stoi(v); });
    v_qsort(vk, 0, result.size() - 1, result.size());
  }

  return 0;
}
