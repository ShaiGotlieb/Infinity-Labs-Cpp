#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"

namespace ilrd
{
    class Rectangle : public Shape
    {
    public:
        Rectangle(Point point, COLORS color, double angle,  
                double width, double height);
        virtual ~Rectangle();
        double GetHeight() const;
        double GetWidth() const;
        void SetWidth(double width);
        void SetHeight(double height);
        virtual void Draw() const;

    private:
        double m_width;
        double m_height;
    };
        
}// namespace ilrd

#endif // RECTANGLE