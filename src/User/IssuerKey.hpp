#ifndef USER_ISSUERKEY_HPP
#define USER_ISSUERKEY_HPP

#include "IssuerPriKey.hpp"
#include "IssuerPubKey.hpp"

#include <string>
#include <iostream>

#include <mcl/bn256.hpp>
class IssuerKey
{
  private:
    User::IssuerPubKey IPubK;
    User::IssuerPriKey IpriK;

    //   public:
    //     IssuerKey(const std::vector<unsigned char> &attributeName)
    //     {
    //     }
};
#endif