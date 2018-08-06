#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "../src/User/IssuerPriKey.h"

#include <mcl/bn256.hpp>

TEST(ISSUER, GENPRIKEY)
{
  User::IssuerPriKey key;
  EXPECT_EQ(64, key.getPriKey().length());
  
  mcl::bn256::G1 P0, P1, P2;
  mcl::bn256::Fr s;
  int i=1;
  mcl::bn256::mapToG1(P0, i);
  s.setStr("1");
  mpz_class ss = s.getMpz();
  mcl::bn256::G1::mulGeneric(P1, P0, ss);
  std::cout << P1.getStr() << std::endl;

  mcl::bn256::G1 P20, P21, P22;
  mcl::bn256::Fr s2;
  mcl::bn256::mapToG1(P0, i);
  s2.setStr("2");
  mpz_class ss2 = s2.getMpz();
  mcl::bn256::G1::mulGeneric(P21, P20, ss2);
  std::cout << P21.getStr() << std::endl;
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}