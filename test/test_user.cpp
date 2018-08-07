#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>

#include "../src/User/IssuerPriKey.hpp"
#include "../src/User/IssuerPubKey.hpp"

TEST(ISSUER, GENPRIKEY)
{
  User::IssuerPriKey key;
  std::string pri_key;
  key.getStrPriKey(pri_key, 16);
  EXPECT_EQ(256, pri_key.length());
}

TEST(ISSUER, GENPUBKEY)
{
  User::IssuerPriKey PriKey;
  mpz_class pri_key;
  PriKey.getMpzPriKey(pri_key);
  User::IssuerPubKey PubKey;
  PubKey.genPubKey(pri_key);
  std::string pub_key;
  PubKey.getStrPubKey(pub_key, 16);
  std::vector<std::string> split_vec;
  boost::split(split_vec, pub_key, boost::is_any_of(" "),
               boost::token_compress_on);
  EXPECT_EQ(split_vec.size(), 5);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}