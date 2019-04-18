#ifndef ILRD_RD61_POLYGON_HPP
#define ILRD_RD61_POLYGON_HPP

#include "point.hpp"

struct Polygon {
    explicit Polygon(size_t numPoints =0);
    Polygon(const Polygon& other);
    ~Polygon();
    Polygon& operator=(const Polygon& other);

    void Add(const Point& p);
    void Print() const;
    bool IsEqual(const Polygon& other) const;

    size_t m_numPoints;
    Point *m_points;
};

void CopyArr(Point *dst, const Point *src, size_t numOfPoints);

#endif