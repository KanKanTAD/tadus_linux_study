#include <cstring>
#include <tadcc/tadcc.hpp>

template <size_t cap_size_ = 125> struct mtx_graph_t {
  int node_count = 0;
  unsigned int graph[cap_size_][cap_size_];
  void clear() { bzero(graph, sizeof(graph)); }
  int enter_degree(const int idx) const {
    int res = 0;
    for (int i = 0; i < node_count; ++i) {
      if (idx == i) {
        continue;
      }
      res += (graph[i][idx]) ? 1 : 0;
    }
    return res;
  }
  int out_degree(const int idx) const {
    int res = 0;
    for (int i = 0; i < node_count; ++i) {
      if (idx == i) {
        continue;
      }
      res += (graph[idx][i]) ? 1 : 0;
    }
    return res;
  }
};

int main(int argc, char **argv) { return 0; }
