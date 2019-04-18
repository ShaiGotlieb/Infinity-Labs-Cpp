#ifndef ILRD_RD61_PRINTECHO_HPP
#define ILRD_RD61_PRINTECHO_HPP

#include "surpriser.hpp"

namespace ilrd{

class PrintEcho 
    : public Surpriser
{
public:
    PrintEcho();
    ~PrintEcho();

    void SurpriseMe();
};

}//ilrd
#endif//ILRD_RD61_PRINTECHO_HPP