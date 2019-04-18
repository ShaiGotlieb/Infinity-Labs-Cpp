#include <iostream> /* std::cout */
#include <cstddef>

#include "point.hpp"
#include "polygon.hpp"
#include "test.hpp"

TestResult TestAdd();
TestResult TestIsEqual();

int main()
{
    RUN_TEST(TestAdd);
    RUN_TEST(TestIsEqual);

    return 0;
}

TestResult TestAdd()
{
    Polygon *polygon = new Polygon(10);
    Point *p1 = new Point(1,1);
    Point *p2 = new Point(2,2);
    Point *p3 = new Point(3,3);
    Point *p4 = new Point(4,4);

    polygon->Add(*p1);
    polygon->Add(*p2);
    polygon->Add(*p3);
    polygon->Add(*p4);

    REQUIRE(polygon->m_numPoints == 14);
    
    return TEST_PASS;
}

TestResult TestIsEqual()
{
    Polygon *polygon1 = new Polygon(10);
    Polygon *polygon2 = new Polygon(10);
    Point *p1 = new Point(1,1);
    Point *p2 = new Point(2,2);
    Point *p3 = new Point(3,3);
    Point *p4 = new Point(4,4);

    polygon1->Add(*p1);
    polygon1->Add(*p2);
    polygon1->Add(*p3);
    polygon1->Add(*p4);

    polygon2->Add(*p1);
    polygon2->Add(*p2);
    polygon2->Add(*p3);
    polygon2->Add(*p4);

    REQUIRE(polygon1->IsEqual(*polygon2));
    
    return TEST_PASS;
}