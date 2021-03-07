#pragma once
#include "string_alg.h"

namespace tadcc {

void pattern_split(const std::string &master__, const std::string &pattern,
                   std::vector<std::string> &result);
void char_split(const std::string &master__, const std::string &seq,
                std::vector<std::string> &result);

}
