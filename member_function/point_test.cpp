#include <iostream>

#include "member_function.hpp"

using namespace std;

int main()
{
    Point p1;
    Point p2;
    Point p3;
    Point added_point;

    p1.m_x = 1;
    p1.m_y = 1;
    p1.parenth_type = ANGULAR;

    p2.m_x = 2;
    p2.m_y = 2;
    p2.parenth_type = CURLY;

    p3.m_x = 3;
    p3.m_y = 3;
    p3.parenth_type = ANGULAR;

    p1.AdjustBy(p2).AdjustBy(p3).AdjustBy(100,100);

   p1.Print('[', ']');

    added_point = Add(p1, p2);

    added_point.Print('(', ')');

    p3.Print(p3.parenth_type);
    p2.Print(p2.parenth_type);
    p1.Print(p1.parenth_type);

    return 0;
}