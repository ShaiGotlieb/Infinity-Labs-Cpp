#ifndef ILRD_RD61_PRINTSURPRISER_HPP
#define ILRD_RD61_PRINTSURPRISER_HPP

#include "surpriser.hpp"

namespace ilrd{

class PrintSurprise : public Surpriser
{
public:
    PrintSurprise();
    ~PrintSurprise();

    void SurpriseMe();
};
}//ilrd
#endif//ILRD_RD61_PRINTSURPRISER_HPP