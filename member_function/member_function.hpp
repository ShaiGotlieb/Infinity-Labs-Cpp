#ifndef __H_MEMBER_FUNCTION_
#define __H_MEMBER_FUNCTION_


enum ParenthesesType { 

    ROUND,
    SQUARE,
    CURLY,
    ANGULAR
};

struct Point
{
    int Length() const;
    Point& AdjustBy(const Point &point);
    Point& AdjustBy(int dx, int dy);
    void Print(char open_bracket, char close_bracket) const;
    void Print(ParenthesesType parenthesesType) const;

    int m_x;
    int m_y;
    ParenthesesType parenth_type;
};

Point Add(Point p1, Point p2);

#endif
