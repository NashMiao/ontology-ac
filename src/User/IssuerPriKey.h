#ifndef USER_ISSUERPRIKEY
#define USER_ISSUERPRIKEY

#include <string>
#include <vector>

#include <cybozu/random_generator.hpp>
#include <mcl/bn256.hpp>
#include <mcl/ecparam.hpp>
#include <mcl/gmp_util.hpp>

typedef mcl::FpT<> Fp;

namespace User
{
class IssuerPriKey
{
  private:
    Fp Key;

  public:
    explicit IssuerPriKey()
    {
        cybozu::RandomGenerator rg;
        const char *p = mcl::ecparam::secp256k1.p;
        Fp::init(p);
        Fp x;
        Key.setRand(rg);
    }

    std::string getPriKey() { return Key.getStr(16); }
};
} // namespace User

#endif