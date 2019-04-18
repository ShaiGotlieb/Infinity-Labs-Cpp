#include "square.hpp"

namespace ilrd 
{
    Square::Square(Point point, COLORS color, double angle, double width)
        : Rectangle(point, color, angle, width, width)

    {
    }

    Square::~Square()
    {
    }

}// namespce ilrd