#include "gtest/gtest.h"
#include "add.h"

TEST(test1, c1){ // NOLINT
  EXPECT_EQ(3, add(1,2));
}