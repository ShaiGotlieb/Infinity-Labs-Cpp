#ifndef __H_POINT_
#define __H_POINT_

struct Point
{
    enum ParenthesesType{     
        ROUND,
        SQUARE,
        CURLY,
        ANGULAR
    } m_parenth_type;

    Point& AdjustBy(const Point &point);
    Point& AdjustBy(int dx, int dy);
    Point& operator = (const Point& other_);
    Point(const Point& other);
    ~Point();

    bool IsEqual(Point other);

    explicit Point();
    explicit Point(int x_, int y_, int limit_ = 100);

    double Length() const;

    void Print(ParenthesesType parenthesesType = ROUND);
    void Print(char open_bracket = '(', char close_bracket = ')');
    void UpdateLength();

    int m_x;
    int m_y;
    int m_last_x;
    int m_last_y;
    mutable double m_length;
    int m_limit;
};

Point Add(Point &p1, Point &p2);
double TotalLength();
double CalcLength(int x, int y);

#endif
