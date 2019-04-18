#include "rectangle.hpp"

namespace ilrd 
{
    Rectangle::Rectangle(Point point, COLORS color, double angle,  
                        double width, double height)
        : Shape(point, color, angle)
        , m_width(width)
        , m_height(height)
    {
    }

    Rectangle::~Rectangle()
    {
    }

    double Rectangle::GetWidth() const
    {
        return m_width;
    }

    double Rectangle::GetHeight() const
    {
        return m_height;
    }

    void Rectangle::SetWidth(double width) 
    {
        m_width = width;
    }

    void Rectangle::SetHeight(double height) 
    {
        m_height = height;
    }

    void Rectangle::Draw() const
    {
        double width = GetWidth() / 2;
        double height = GetHeight() / 2;

        Point *pointA = new Point(GetCenter().GetX() - width, 
                                    GetCenter().GetY() + height);
        pointA->Revolve(GetCenter(), GetAngle());
        Point *pointB = new Point(GetCenter().GetX() + width, 
                                    GetCenter().GetY() + height);
        pointB->Revolve(GetCenter(), GetAngle());
        Point *pointC = new Point(GetCenter().GetX() + width, 
                                    GetCenter().GetY() - height);
        pointC->Revolve(GetCenter(), GetAngle());
        Point *pointD = new Point(GetCenter().GetX() - width, 
                                    GetCenter().GetY() - height);
        pointD->Revolve(GetCenter(), GetAngle());
        
        DrawPolygon(GetColor(), 4, 
                    (int)pointA->GetX(), (int)pointA->GetY(),
                    (int)pointB->GetX(), (int)pointB->GetY(), 
                    (int)pointC->GetX(), (int)pointC->GetY(),
                    (int)pointD->GetX(), (int)pointD->GetY());
    }

}// namespce ilrd