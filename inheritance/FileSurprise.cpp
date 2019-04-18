#include <iostream> //cout
#include <fstream> // std::ofstream

#include "FileSurprise.hpp"

using namespace ilrd;

FileSurprise::FileSurprise()
{
}

FileSurprise::~FileSurprise()
{
}

void FileSurprise::SurpriseMe()
{
    std::cout << "file created!" << std::endl;
    std::ofstream ofs ("nothing_here.txt", std::ofstream::out);

    ofs.close();
}