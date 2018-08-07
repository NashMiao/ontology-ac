#ifndef USER_ISSUERPRIKEY
#define USER_ISSUERPRIKEY

#include <string>
#include <vector>

#include <mcl/bn256.hpp>
#include <mcl/ecparam.hpp>
#include <mcl/gmp_util.hpp>

namespace User
{
class IssuerPriKey
{
private:
  mpz_class Key;

public:
  explicit IssuerPriKey(size_t bit_size = 1024)
  {
    mcl::gmp::getRand(Key, bit_size);
  }

  void getStrPriKey(std::string &str_pri_key, int base = 10) { str_pri_key = Key.get_str(base); }
  void getMpzPriKey(mpz_class &mpz_pri_key) { mpz_pri_key = Key; }
};
} // namespace User

#endif