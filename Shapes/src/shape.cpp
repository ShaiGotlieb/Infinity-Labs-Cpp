
#include "shape.hpp"

namespace ilrd
{
    Shape::Shape()
    {
    }
    Shape::Shape(Point point, COLORS color, double angle)
        : m_pivot(point)
        , m_color(color)
        , m_angle(angle)
    {
    }
    
    Shape::~Shape()
    {
    }

    COLORS Shape::GetColor() const
    {
        return m_color; 
    }

    void Shape::SetColor(COLORS color)
    {
        m_color = color;
    }

    Point Shape::GetCenter() const
    {
        return m_pivot;
    }

    Point Shape::SetCenter(Point pivot)
    {
        m_pivot = pivot;
        return m_pivot;
    }

    double Shape::GetAngle() const
    {
        return m_angle;
    }

    Shape& Shape::Move(Point moveToPoint)
    {
        m_pivot = moveToPoint;
        return *this;
    }

    Shape& Shape::Move(double xNewLocation, double yNewLocation)
    {
        Step(&m_pivot, xNewLocation, yNewLocation);
        return *this;
    }

    Shape& Shape::Rotate(double angle)
    {
        m_angle += angle;
        return *this;
    }

    Shape& Shape::Revolve(Point point, double angle)
    {
        m_pivot = m_pivot.Revolve(point, angle);
        return *this;
    }
}