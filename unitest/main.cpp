#include <iostream>
#include <gtest/gtest.h>

#include "globalheaders.h"

using namespace std;

TEST(test1, eq) {
    using namespace test1;
    ASSERT_TRUE(run() == output());
}

TEST(test2, eq) {
    using namespace test2;
    ASSERT_TRUE(run() == output());
}

TEST(test3, eqMT) {
    using namespace test3;
    ASSERT_TRUE(run() == output());
}

TEST(test4, eqMT) {
    using namespace test4;
    ASSERT_TRUE(run() == output());
}

TEST(test5, timing) {
    using namespace test5;
    ASSERT_FALSE(run());//解析结果必须非空
    run();
}

TEST(test6, timing) {
    using namespace test6;
    ASSERT_FALSE(run());
    run();;
}


int main() {
    //test5::run();;;
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}