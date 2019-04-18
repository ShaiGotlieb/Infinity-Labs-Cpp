#include <cstdlib>  /* rand */
#include <ctime> /* time */
#include <vector> /* vector */

#include "surpriser.hpp"
#include "PrintSurprise.hpp"
#include "FileSurprise.hpp"
#include "PrintEcho.hpp"

int const SURPRISE_SIZE = 3;

namespace ilrd
{

Surpriser::Surpriser()
{
}

Surpriser::~Surpriser()
{
}

Surpriser* GetRandomSurprise()
{
    std::vector<Surpriser*> surprisers;

    surprisers.push_back(new PrintSurprise());
    surprisers.push_back(new PrintEcho());
    surprisers.push_back(new FileSurprise());

    int randomSurpriseAtIndex;
    srand (time(NULL));
    randomSurpriseAtIndex = rand() % SURPRISE_SIZE;

    Surpriser *returnSurprise = surprisers.at(randomSurpriseAtIndex);

    return returnSurprise;
}

void Surpriser::SurpriseMe()
{
}

}//namespace ilrd