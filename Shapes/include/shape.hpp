#ifndef SHAPE
#define SHAPE

#include "glut_utils.h"
#include "point.hpp"

namespace ilrd
{
    class Shape
    {
    public:
        explicit Shape();
        explicit Shape(Point point, COLORS color, double angle = 0);
        virtual ~Shape();
        virtual COLORS GetColor() const;
        virtual Point GetCenter() const;
        virtual Point SetCenter(Point pivot);
        virtual Shape& Move(Point moveToPoint);
        virtual Shape& Move(double xNewLocation, double yNewLocation);
        virtual Shape& Revolve(Point point, double angle);
        virtual Shape& Rotate(double angle);
        virtual double GetAngle() const;
        virtual void Draw() const {}
        virtual void SetColor(COLORS color);

    private:
        Point m_pivot;
        COLORS m_color;
        double m_angle;
    };
        
}// namespace ilrd

#endif // SHAPE