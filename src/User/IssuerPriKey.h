#ifndef USER_ISSUERPRIKEY
#define USER_ISSUERPRIKEY

#include <string>
#include <vector>

#include <cybozu/random_generator.hpp>
#include <mcl/bn256.hpp>
#include <mcl/ecparam.hpp>
#include <mcl/gmp_util.hpp>

typedef mcl::FpT<> Fp;
typedef mcl::EcT<Fp> Ec;

namespace User
{
class IssuerPriKey
{
private:
  const char *p = mcl::ecparam::secp256k1.p;
  Fp Key;

public:
  explicit IssuerPriKey()
  {
    cybozu::RandomGenerator rg;
    Fp::init(p);
    Fp x;
    Key.setRand(rg);
  }

  std::string getPriKey() { return Key.getStr(16); }
  // std::string genPubKey()
  // {
   
  //   mcl::bn256::G1().mulGeneric()
  // }
};
} // namespace User

#endif