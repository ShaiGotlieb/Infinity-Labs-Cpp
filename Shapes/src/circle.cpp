#include "circle.hpp"

namespace ilrd
{
    Circle::Circle(Point point, COLORS color, double angle, double radius)
        : Shape(point, color, angle)
        , m_radius(radius)
    {
    }
    
    Circle::~Circle()
    {
    }

    double Circle::GetRadius() const
    {
        return m_radius;
    }

    void Circle::SetRadius(double radius)
    {
        m_radius = radius;
    }

    void Circle::Draw() const
    {
        DrawCircle(GetColor(), (int)GetCenter().GetX(), (int)GetCenter().GetY(), GetRadius());
    }
    
}// namecpae ilrd