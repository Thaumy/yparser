#include <iostream>
#include <gtest/gtest.h>

#include "globalheaders.h"

using namespace std;

TEST(parse_test1, eq) {
    auto s1 = parse_test1();
    auto s2 = parse_test1_output();
    ASSERT_TRUE(s1 == s2);
}

TEST(parse_test2, eq) {
    auto s1 = parse_test2();
    auto s2 = parse_test2_output();
    ASSERT_TRUE(s1 == s2);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}