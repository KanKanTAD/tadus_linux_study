#pragma once
#include "string_alg.h"
#include <algorithm>

namespace tadcc {

inline bool chr_in_str(char c, const std::string &s) {
  return s.find(c) != s.npos;
}

void trim(std::string &cont__, const std::string &s) {
  rtrim(cont__, s);
  ltrim(cont__, s);
}

void rtrim(std::string &cont__, const std::string &s) {
  while (!cont__.empty()) {
    if (chr_in_str(cont__.back(), s)) {
      cont__.pop_back();
    } else {
      break;
    }
  }
}

void ltrim(std::string &cont__, const std::string &s) {
  std::reverse(cont__.begin(), cont__.end());
  rtrim(cont__, s);
  std::reverse(cont__.begin(), cont__.end());
}

void pattern_split(const std::string &master__, const std::string &pattern,
                   std::vector<std::string> &result) {}
void char_split(const std::string &master__, const std::string &seq,
                std::vector<std::string> &result) {}

} // namespace tadcc
