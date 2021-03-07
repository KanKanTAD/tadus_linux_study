#pragma once

#include <string>
#include <vector>

namespace tadcc {

void trim(std::string &cont__, const std::string &s = " \t\r\n");
void rtrim(std::string &cont__, const std::string &s = " \t\r\n");
void ltrim(std::string &cont__, const std::string &s = " \t\r\n");

void pattern_split(const std::string &master__, const std::string &pattern,
                   std::vector<std::string> &result);
void char_split(const std::string &master__, const std::string &seq,
                std::vector<std::string> &result);

} // namespace tadcc
