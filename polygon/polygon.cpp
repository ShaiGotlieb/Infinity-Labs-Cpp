#include <cstddef> /* size_t */
#include <cstdio>


#include "point.hpp"
#include "polygon.hpp"

Polygon::Polygon(size_t numPoints)
    : m_numPoints(numPoints)
    , m_points(new Point[m_numPoints])
{
}

Polygon::Polygon(const Polygon& other)
    : m_numPoints(other.m_numPoints)
    , m_points(new Point[other.m_numPoints])
{
    CopyArr(m_points, other.m_points, m_numPoints);
}

Polygon::~Polygon()
{
    delete[] m_points;
}

Polygon& Polygon::operator=(const Polygon& other)
{
    delete[] m_points;

    m_numPoints = other.m_numPoints;
    m_points = new Point[m_numPoints];
    CopyArr(m_points, other.m_points, m_numPoints);

    return *this;
}

void Polygon::Add(const Point& p)
{
    Point *pointsArr = new Point[m_numPoints + 1];
    CopyArr(pointsArr, m_points, m_numPoints);
    ++m_numPoints;
    pointsArr[m_numPoints] = p;

    m_points = pointsArr;  
}

bool Polygon::IsEqual(const Polygon& other) const
{
    printf("HERE1?");
    if (m_numPoints != other.m_numPoints) 
    {
        return false;
    }
    for(size_t i = 0; i < other.m_numPoints; i++)
    {
        if (!m_points[i].IsEqual(other.m_points[i])) 
        {
            return false;
        }
    }
    
    return true;
}

void CopyArr(Point *dst, const Point *src, size_t numOfPoints)
{
    for(size_t i = 0; i < numOfPoints; ++i)
    {
       dst[i] = src[i];
    }
}

void Polygon::Print() const
{
    for(size_t i = 0; i < m_numPoints; ++i)
    {
        m_points[i].Print('(');
    }   
}