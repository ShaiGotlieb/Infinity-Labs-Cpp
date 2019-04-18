#include "line.hpp"

namespace ilrd 
{
    Line::Line(Point point, COLORS color, double angle, double length)
        : Shape(point, color, angle)
        , m_length(length)
    {
    }

    Line::~Line()
    {
    }

    double Line::GetLength() const
    {
        return m_length;
    }

    void Line::SetLength(double length) 
    {
        m_length = length;
    }

    void Line::Draw() const
    {
        double offset = GetLength() / 2;
        Point *pointA = new Point(GetCenter().GetX() - offset, 
                                    GetCenter().GetY());
        pointA->Revolve(GetCenter(), GetAngle());
        Point *pointB = new Point(GetCenter().GetX() + offset, 
                                    GetCenter().GetY());
        pointB->Revolve(GetCenter(), GetAngle());
        
        DrawPolygon(GetColor(), 2, 
                    (int)pointA->GetX(), (int)pointA->GetY(),
                    (int)pointB->GetX(), (int)pointB->GetY());
    }

}// namespce ilrd