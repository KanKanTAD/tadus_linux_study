#include <cstdio>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <tadcc.hpp>

TEST(string_alg,trim){
	std::string s = "  abc\t  ";
	std::string s0 = "abc";
	tadcc::trim(s);
	ASSERT_EQ(s,s0);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
