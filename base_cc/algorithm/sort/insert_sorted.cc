#include <algorithm>
#include <iostream>
#include <iterator>
#include <tadcc/string_alg.h>
#include <vector>

template <typename Tp> inline static void show_arr(const std::vector<Tp> &vk) {
  std::copy(vk.begin(), vk.end(), std::ostream_iterator<int>(std::cout, ","));
  std::cout << std::endl;
}
template <typename ItTp> void insert_sort(ItTp beg__, ItTp end__) {
  auto len_ = std::distance(beg__, end__);
  auto last_ = beg__ + len_ - 1;
  for (auto it = last_ - 1; it != beg__; it--) {
    auto tag = *it;
    auto jt = it + 1;
    for (; jt != end__ && tag > *jt; jt++) {
      *(jt - 1) = *jt;
    }
    *(jt - 1) = tag;
  }
}

template <typename Tp> void insert_sort(std::vector<Tp> &vk) {
  for (int i = 1; i < vk.size(); ++i) {
    auto t = vk.at(i);
    auto j = i - 1;
    while (j >= 0 && t > vk.at(j)) {
      vk.at(j + 1) = vk.at(j);
      show_arr(vk);
      --j;
    }
    vk.at(j + 1) = t;
  }
}

int main(int argc, char **argv) {
  std::vector<std::string> result;
  tadcc::pattern_split(argv[1], ",", result);
  std::vector<int> vk;
  std::transform(result.begin(), result.end(), std::back_inserter(vk),
                 [](const std::string &v) { return std::stoi(v); });
  insert_sort(vk.begin(), vk.end());
  show_arr(vk);
  return 0;
}
