#include <iostream> // std::cout
#include <math.h> // pow, sqrt

#include "point.hpp"

static double g_total_length = 0;
const int g_num_of_parantheses = 3;

Point::Point()
{
    m_x = 0;
    m_y = 0;

    m_last_x = 0;
    m_last_y = 0;

    m_length = 0;
    m_limit = 0;
    m_parenth_type = ROUND;
}

Point::Point(int x_, int y_, int limit_)
            : m_x(x_), m_y(y_), m_limit(limit_)
{
    m_last_x = x_;
    m_last_y = y_;

    m_length = 0;
    m_length = Length();

    g_total_length += m_length;
    m_parenth_type = ROUND;
}

Point::Point(const Point& other_)
    : m_x(other_.m_x), m_y(other_.m_y)
{
    m_last_x = other_.m_last_x;
    m_last_y = other_.m_last_y;
    
    m_length = other_.m_length;
    m_limit = other_.m_limit;
    m_parenth_type = other_.m_parenth_type;
}

Point& Point::operator=(const Point& other_)
{
    m_x = other_.m_x;
    m_y = other_.m_y;

    m_last_x = other_.m_last_x;
    m_last_y = other_.m_last_y;

    m_length = other_.m_length;
    m_limit = other_.m_limit;
    m_parenth_type = other_.m_parenth_type;

    return *this;
}

Point::~Point()
{
    m_x = 0;
    m_y = 0;

    m_last_x = 0;
    m_last_y = 0;

    g_total_length -= m_length;
    m_length = 0;
    m_limit = 0;
}

void Point::UpdateLength()
{
    g_total_length -= m_length;
    m_length = Length();
    g_total_length +=m_length;
}

Point& Point::AdjustBy(const Point &point)
{
    m_x += point.m_x;
    m_x %= m_limit;

    m_y += point.m_y;
    m_y %= m_limit;

    m_last_x = m_x;
    m_last_y = m_last_y;

    UpdateLength();

    return *this;
}

Point& Point::AdjustBy(int dx, int dy)
{
    m_x += dx;
    m_x %= m_limit;

    m_y += dy;
    m_y %= m_limit;

    m_last_x = m_x;
    m_last_y = m_last_y;

   UpdateLength();
    
    return *this;
}

double Point::Length() const
{
    if (m_last_x == m_x && m_last_y == m_y && m_length != 0) 
    {
        return m_length;
    }
    
    m_length = CalcLength(m_x, m_y);

    return m_length;
}

bool Point::IsEqual(Point other)
{
    if (this->m_x == other.m_x && this->m_y == other.m_y) 
    {
        return true;
    }

    return false;
}

void Point::Print(char open_bracket, char close_bracket)
{
    std::cout << open_bracket << m_x << "," << m_y << close_bracket << "\n";
}

void Point::Print(ParenthesesType parentheses) 
{
    const char *open_parenthesis = "([{<";
    const char *close_parenthesis = ")]}>";
    char close = close_parenthesis[parentheses];
    char open = open_parenthesis[parentheses];

    if (g_num_of_parantheses < parentheses) 
    {
        open = open_parenthesis[0];
        close = close_parenthesis[0];
    }
    
    Print(open, close);
}

double TotalLength()
{
    return g_total_length;
}

Point Add(Point &p1, Point &p2)
{
    Point point_to_add(p1.m_x + p2.m_x, p1.m_y + p2.m_y);

    return point_to_add;
}

double CalcLength(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}