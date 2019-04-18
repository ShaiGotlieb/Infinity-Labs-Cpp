#ifndef ILRD_RD61_FILESURPRISER_HPP
#define ILRD_RD61_FILESURPRISER_HPP

#include "surpriser.hpp"

namespace ilrd
{

class FileSurprise : public Surpriser
{
public:
    FileSurprise();
    ~FileSurprise();

    void SurpriseMe();
};

}//ilrd
#endif//ILRD_RD61_FILESURPRISER_HPP