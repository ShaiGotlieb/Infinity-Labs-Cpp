#include <iostream>
#include <cstdio>

#include "point.hpp"

int main()
{
    Point p1;
    Point p2;
    Point p3(2,2);
    Point p4(2,2);

    p4.AdjustBy(p3);

    p3.Length();
    p4.Length();

    p1.Print('{', '}');
    p2.Print('[', ']');
    p3.Print(p1.m_parenth_type);
    p4.Print('<', '>');

    printf("Total Length is: %f\n", TotalLength());
    
    p1 = Add(p3,p4);

    printf("Point3 + point4 = ");
    p1.Print('{', '}');
    
    return 0;
}