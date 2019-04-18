#include <iostream>
#include <math.h> // pow, sqrt

#include "member_function.hpp"

using namespace std;

Point& Point::AdjustBy(const Point &point)
{
    m_x += point.m_x;
    m_y += point.m_y;

    return *this;
}

Point& Point::AdjustBy(int dx, int dy)
{
    m_x += dx;
    m_y += dy;

    return *this;
}

int Point::Length() const
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

void Point::Print(char open_bracket, char close_bracket) const
{
    cout << open_bracket << m_x << "," << m_y << close_bracket << "\n";
}

void Point::Print(ParenthesesType parentheses) const
{
    switch (parentheses)
    {
        case ROUND:
            cout << '(' << m_x << "," << m_y << ')' << "\n";
            break;

        case SQUARE:
            cout << '[' << m_x << "," << m_y << ']' << "\n";
            break;

        case CURLY:
            cout << '{' << m_x << "," << m_y << '}' << "\n";
            break;

        case ANGULAR:
            cout << '<' << m_x << "," << m_y << '>' << "\n";
            break;

        default:
            break;
    }
}

Point Add(Point p1, Point p2)
{
    Point point_to_add;

    point_to_add.m_x = p1.m_x + p2.m_x;
    point_to_add.m_y = p1.m_y + p2.m_y;

    return point_to_add;
}
