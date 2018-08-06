#ifndef USER_H
#define USER_H

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

class CredRequest
{
  private:
    mcl::bn256::G1 Nym;
    Fp IssuerNonce;
    Fp ProofC;
    Fp ProofS;
};

class Credential
{
  private:
    mcl::bn256::G1 A;
    mcl::bn256::G1 B;
    Fp E;
    Fp S;
    Fp Attrs[];
};

class Signature
{
  private:
    mcl::bn256::G1 APrime;
    mcl::bn256::G1 ABar;
    mcl::bn256::G1 BPrime;

    Fp ProofC;

    // response in sigma-protocol
    Fp ProofSSk;
    Fp ProofSE;
    Fp ProofSR2;
    Fp ProofSR3;
    Fp ProofSSPrime;
    std::vector<Fp> ProofSAttrs;

    Fp Nonce;
    mcl::bn256::G1 Nym;
};

} // namespace User
#endif