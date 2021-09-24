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

TEST(test3, timing) {
    using namespace test3;
    ASSERT_FALSE(run());//解析结果必须非空
    run();
}

TEST(test4, timing) {
    using namespace test4;
    ASSERT_FALSE(run());
    run();;
}


int main() {
    //test4::run();;;
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}