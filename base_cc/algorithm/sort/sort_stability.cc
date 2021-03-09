#include <algorithm>
#include <iostream>
#include <vector>
template <typename Tp> struct Val {
  Tp value;
  int flag;
  Val() : Val(0, 0) {}
  Val(const Tp v, int f) : value(v), flag(f) {}
  template <typename T> static void show_vec(const std::vector<Val<T>> &vals) {
    for (const auto &v : vals) {
      std::cout << v.value << ":" << v.flag << " ,";
    }
    std::cout << std::endl;
  }
};

int main() {

  std::vector<Val<int>> vals;
  vals.emplace_back(20, 1);
  vals.emplace_back(20, 2);
  vals.emplace_back(3, 1);
  vals.emplace_back(20, 3);
  vals.emplace_back(12, 1);
  vals.emplace_back(3, 2);
  vals.emplace_back(2, 1);
  vals.emplace_back(1, 1);

  Val<int>::show_vec(vals);

  std::sort(vals.begin(), vals.end(), [](const Val<int> &a, const Val<int> &b) {
    return a.value < b.value;
  });
  Val<int>::show_vec(vals);
  return 0;
}
