#include "group.hpp"

namespace ilrd 
{
    Group::Group()
    {
    }

    Group::~Group()
    {
        m_shapes.erase(m_shapes.begin(), m_shapes.end());
    }

    void Group::AddShape(Shape *shape)
    {
        m_shapes.push_back(shape);
        SetCenter(CalculateCenter());
    }

    void Group::Draw() const
    {
        for (size_t i = 0; i < m_shapes.size(); i++)
        {
            m_shapes.at(i)->Draw();
        }
    }

    Shape& Group::Move(Point moveToPoint)
    {
        Move(moveToPoint.GetX() - GetCenter().GetX(), 
            moveToPoint.GetY() - GetCenter().GetY());

        // SetCenter(CalculateCenter());
        return *this;
    }

    Shape& Group::Move(double x, double y)
    {
        for (size_t i = 0; i < m_shapes.size(); i++)
        {
            m_shapes.at(i)->Move(x,y);
        }

        SetCenter(CalculateCenter());

        return *this;
    }

    Shape& Group::Revolve(Point point, double angle)
    {
        return Move(GetCenter().Revolve(point, angle));
    }

    Shape& Group::Rotate(double angle)
    {
        for (size_t i = 0; i < m_shapes.size(); i++)
        {
            m_shapes.at(i)->Rotate(angle);
            m_shapes.at(i)->Revolve(GetCenter(), angle);
        }

        return *this;
    }

    void Group::SetColor(COLORS color)
    {
        for (size_t i = 0; i < m_shapes.size(); i++)
        {
            m_shapes.at(i)->SetColor(color);
        }        
    }

    Point Group::CalculateCenter()
    {
        int sumX = 0;
        int sumY = 0;
        size_t totalSize = m_shapes.size();
        
        for (size_t i = 0; i < totalSize; i++)
        {
            sumX =+ m_shapes.at(i)->GetCenter().GetX();
            sumY =+ m_shapes.at(i)->GetCenter().GetY();
        }

        return Point(sumX / totalSize , sumY / totalSize);
    }

}// namespce ilrd