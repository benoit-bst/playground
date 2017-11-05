#include "classe_de_test.h"

#include <gtest/gtest.h>

TEST(squarerootTest, PositiveNos){
  ASSERT_EQ(6,squareroot(36.0));
  ASSERT_EQ(18.0,squareroot(324.0));
  ASSERT_EQ(25.4,squareroot(645.16));
  ASSERT_EQ(0,squareroot(0.0));
}

TEST(squarerootTest, NegativeNos){
  ASSERT_EQ(-1.0,squareroot(-15.0));
  ASSERT_EQ(-1.0,squareroot(-0.2));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}