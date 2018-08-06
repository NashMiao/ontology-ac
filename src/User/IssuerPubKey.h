#ifndef USER_ISSUERPUBKEY_HPP
#define USER_ISSUERPUBKEY_HPP

#include <string>
#include <vector>

#include <cybozu/random_generator.hpp>
#include <mcl/bn256.hpp>
#include <mcl/ecparam.hpp>
#include <mcl/gmp_util.hpp>

typedef mcl::FpT<> Fp;

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

    Fp ProofC;
    Fp ProofS;
    
};
} // namespace User
#endif