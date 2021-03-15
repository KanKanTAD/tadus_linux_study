#include <algorithm>
#include <iterator>
#include <type_traits>

template <typename ItTp> void heap_sort(ItTp, ItTp);
int main() { return 0; }

template <typename ItTp>
void heapify(ItTp beg__, const size_t n, const size_t idx) {
  auto node_idx = idx;
  auto left = idx * 2 + 1;
  auto right = idx * 2 + 2;
  if (left < n && *(beg__ + node_idx) < *(beg__ + left)) {
    node_idx = left;
  }
  if (right < n && *(beg__ + node_idx) < *(beg__ + right)) {
    node_idx = right;
  }
  if (node_idx != idx) {
    std::swap(*(beg__ + node_idx), *(beg__ + idx));
    heapify(beg__, n, node_idx);
  }
}
template <typename ItTp> void heap_sort(ItTp beg__, ItTp end__) {
  auto n = std::distance(beg__, end__);
  for (int i = n / 2; i >= 0; --i) {
    heapify(beg__, n, i);
  }
  for (int i = n - 1; i > 0; --i) {
    std::swap(*beg__, *(beg__ + i));
    heapify(beg__, i, 0);
  }
}
