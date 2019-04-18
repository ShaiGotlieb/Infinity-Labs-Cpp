#include <cstdlib> //EXIT_SUCCESS

#include "surpriser.hpp"

using namespace ilrd;

int main()
{
	Surpriser *todaySurprise = GetRandomSurprise();

	todaySurprise->SurpriseMe();

	return (EXIT_SUCCESS);
}