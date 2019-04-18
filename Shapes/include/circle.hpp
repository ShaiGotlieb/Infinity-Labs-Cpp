#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"

namespace ilrd
{
    class Circle : public Shape
    {
    public:
        Circle(Point point, COLORS color, double angle,  double radius);
        virtual ~Circle();
        double GetRadius() const;
        void SetRadius(double radius);
        virtual void Draw() const;

    private:
        double m_radius;
    };
        
}// namespace ilrd

#endif // CIRCLE