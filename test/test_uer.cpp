#include <string>

#include <gtest/gtest.h>

#include "../src/User/IssuerPriKey.hpp"

TEST(ISSUER, GENPRIKEY)
{
  User::IssuerPriKey key;
  EXPECT_EQ(64, key.getPriKey().length());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}