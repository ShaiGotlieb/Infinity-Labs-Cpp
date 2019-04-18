#ifndef SQUARE
#define SQUARE

#include "rectangle.hpp"

namespace ilrd
{
    class Square : public Rectangle
    {
    public:
        Square(Point point, COLORS color, double angle,  
                double width);
        virtual ~Square();
    };
        
}// namespace ilrd

#endif // SQUARE