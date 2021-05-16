#include <gtest/gtest.h>
#include "folly/MicroSpinLock.h"
#include "folly/RWSpinLock.h"

int foobar(void)
{
    return 1;
}

TEST(foobar, test)
{
    ASSERT_EQ(1, foobar());
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
