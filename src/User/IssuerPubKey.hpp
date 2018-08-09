#ifndef USER_ISSUERPUBKEY_HPP
#define USER_ISSUERPUBKEY_HPP

#include <string>
#include <vector>

#include <amcl/big.h>

namespace User
{
class IssuerPubKey
{
private:
  std::vector<std::string> AttributeNames;

  mcl::bn256::G1 HSk;
  mcl::bn256::G1 HRand;
  std::vector<mcl::bn256::G1> HAttrs;

  mcl::bn256::G2 W;

  mcl::bn256::G1 G1;
  mcl::bn256::G2 G2;

  mpz_class ProofC;
  mpz_class ProofS;

public:
  void genPubKey(const mpz_class &pri_key)
  {
    mcl::bn256::initPairing();
    mcl::bn256::G2 g2;
    mcl::bn256::mapToG2(g2, 1);
    mcl::bn256::G2::mulGeneric(W, g2, pri_key);
  }
  void getStrPubKey(std::string &pub_key, int base = 10)
  {
    pub_key = W.getStr(base);
  }
};
} // namespace User
#endif