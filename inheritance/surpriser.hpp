#ifndef ILRD_RD61_SURPRISER_HPP
#define ILRD_RD61_SURPRISER_HPP

namespace ilrd
{
    
class Surpriser
{
public:
    Surpriser();
    ~Surpriser();

    virtual void SurpriseMe();
};

Surpriser* GetRandomSurprise();
}//ilrd

#endif//ILRD_RD61_SURPRISER_HP


